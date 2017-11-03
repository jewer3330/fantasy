#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_comparefloat.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroyactor.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_15021_IsTrigger = 0;
uint64_t Variable_15021_BuffID = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(15021, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 4, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(15021, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(15021, 2) {
}

REGISTER_CREATE_SKILL_NODE(15021, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(15021, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(15021, 3) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 5, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    if (node3 == nullptr) {
        node3 = new PhaseNode_GetLocation(3, phase);
        node3->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node3->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15021, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(15021, 4) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_ResetCD::TRIGGER_DONE, 89, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_ResetCD::TRIGGER_DONE, 3, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_ResetCD);
    if (node4 == nullptr) {
        node4 = new PhaseNode_ResetCD(4, phase);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node4->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node4->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(15021, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(15021, 5) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnCollider::TRIGGER_DONE, 33, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15021, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_SpawnCollider);
    if (node5 == nullptr) {
        node5 = new PhaseNode_SpawnCollider(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setMesh("");
        node5->setMeshScale(.00f);
        node5->setEffectID(101121);
        node5->setEffectScale(1.00f);
        node5->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node5->setTypeParams(0, .00f);
        node5->setTime(.00f);
        node5->setPosZ(.00f);
        node5->setRotation(.00f);
        node5->setreentry(false);
        node5->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(15021, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    if (node3 != nullptr) node5->setPosX(node3->getX());
    if (node3 != nullptr) node5->setPosY(node3->getY());
    return node5;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15021, 6) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 13, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15021, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_PlayAnimation);
    if (node6 == nullptr) {
        node6 = new PhaseNode_PlayAnimation(6, phase);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node6->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node6->setTarget(0U);
        node6->setAnimation("Skill1S1");
        node6->setParameter("");
        node6->setValue(false);
        CALL_REGISTER_SKILL_NODE(15021, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(15021, 12) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_DestroyCollider::TRIGGER_DONE, 119, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(15021, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_DestroyCollider);
    if (node12 == nullptr) {
        node12 = new PhaseNode_DestroyCollider(12, phase);
        CALL_REGISTER_SKILL_NODE(15021, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 != nullptr) node12->setColliderID(node50->getColliderID());
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15021, 13) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 14, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15021, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_Delay);
    if (node13 == nullptr) {
        node13 = new PhaseNode_Delay(13, phase);
        node13->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(15021, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15021, 14) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 15, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15021, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_PlayAnimation);
    if (node14 == nullptr) {
        node14 = new PhaseNode_PlayAnimation(14, phase);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node14->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node14->setTarget(0U);
        node14->setAnimation("Skill1S2");
        node14->setParameter("");
        node14->setValue(false);
        CALL_REGISTER_SKILL_NODE(15021, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15021, 15) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15021, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Delay);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Delay(15, phase);
        node15->setTime(1.00f);
        CALL_REGISTER_SKILL_NODE(15021, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15021, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 17, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15021, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Skill1S3");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(15021, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15021, 17) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyActor>(PhaseNode_Delay::TRIGGER_DONE, 18, PhaseNode_DestroyActor::FUNC_DO, &PhaseNode_DestroyActor::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Delay);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Delay(17, phase);
        node17->setTime(1.10f);
        CALL_REGISTER_SKILL_NODE(15021, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// DestroyActor
//
REGISTER_REGISTER_SKILL_NODE(15021, 18) {
    pnode->resizeTrigger(PhaseNode_DestroyActor::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_DestroyActor::TRIGGER_DONE, 19, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(15021, 18) {
    auto node18 = GET_SKILL_NODE(18, PhaseNode_DestroyActor);
    if (node18 == nullptr) {
        node18 = new PhaseNode_DestroyActor(18, phase);
        node18->setActorID(0U);
        CALL_REGISTER_SKILL_NODE(15021, 18, node18)
    }
    if (noInit == true) {
        return node18;
    }
    return node18;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(15021, 19) {
}

REGISTER_CREATE_SKILL_NODE(15021, 19) {
    auto node19 = GET_SKILL_NODE(19, PhaseNode_EndPhase);
    if (node19 == nullptr) {
        node19 = new PhaseNode_EndPhase(19, phase);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node19->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(15021, 19, node19)
    }
    if (noInit == true) {
        return node19;
    }
    return node19;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(15021, 20) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 6, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15021, 20) {
    auto node20 = GET_SKILL_NODE(20, PhaseNode_SpawnCollider);
    if (node20 == nullptr) {
        node20 = new PhaseNode_SpawnCollider(20, phase);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node20->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node20->setMesh("");
        node20->setMeshScale(.00f);
        node20->setEffectID(101123);
        node20->setEffectScale(1.00f);
        node20->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node20->setTypeParams(0, .00f);
        node20->setTime(.00f);
        node20->setPosZ(.00f);
        node20->setRotation(.00f);
        node20->setreentry(false);
        node20->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(15021, 20, node20)
    }
    if (noInit == true) {
        return node20;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    if (node3 != nullptr) node20->setPosX(node3->getX());
    if (node3 != nullptr) node20->setPosY(node3->getY());
    return node20;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15021, 33) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 50, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_Delay);
    if (node33 == nullptr) {
        node33 = new PhaseNode_Delay(33, phase);
        node33->setTime(.80f);
        CALL_REGISTER_SKILL_NODE(15021, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(15021, 50) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_SpawnCollider::TRIGGER_DONE, 175, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15021, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 == nullptr) {
        node50 = new PhaseNode_SpawnCollider(50, phase);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node50->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node50->setMesh("");
        node50->setMeshScale(.00f);
        node50->setEffectID(0);
        node50->setEffectScale(.00f);
        node50->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node50->setTypeParams(0, .50f);
        node50->setTime(.00f);
        node50->setPosZ(.00f);
        node50->setRotation(.00f);
        node50->setreentry(false);
        node50->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(15021, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    auto node3 = GET_SKILL_NODE(3, PhaseNode_GetLocation);
    if (node3 != nullptr) node50->setPosX(node3->getX());
    if (node3 != nullptr) node50->setPosY(node3->getY());
    return node50;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(15021, 85) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 87, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(15021, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_Detect);
    if (node85 == nullptr) {
        node85 = new PhaseNode_Detect(85, phase);
        node85->setSelf(0U);
        node85->setEvent("");
        node85->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node85->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(15021, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(15021, 87) {
}

REGISTER_CREATE_SKILL_NODE(15021, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_EndPhase);
    if (node87 == nullptr) {
        node87 = new PhaseNode_EndPhase(87, phase);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node87->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(15021, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15021, 89) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 115, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15021, 89) {
    auto node89 = GET_SKILL_NODE(89, PhaseNode_Delay);
    if (node89 == nullptr) {
        node89 = new PhaseNode_Delay(89, phase);
        node89->setTime(2.00f);
        CALL_REGISTER_SKILL_NODE(15021, 89, node89)
    }
    if (noInit == true) {
        return node89;
    }
    return node89;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(15021, 91) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 150, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(15021, 91) {
    auto node91 = GET_SKILL_NODE(91, PhaseNode_AddSkillBuff);
    if (node91 == nullptr) {
        node91 = new PhaseNode_AddSkillBuff(91, phase);
        node91->setConfigID(250213);
        node91->setConfigIDs({});
        node91->setTarget(0U);
        node91->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(15021, 91, node91)
    }
    if (noInit == true) {
        return node91;
    }
    return node91;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(15021, 96) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 20, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_RemoveSkillBuff);
    if (node96 == nullptr) {
        node96 = new PhaseNode_RemoveSkillBuff(96, phase);
        node96->setBuffIDs({});
        node96->setConfigID(0);
        node96->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(15021, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    auto variables = node96->getVariables();
    if (variables != nullptr) {
        node96->setBuffID(variables->getVariable<uint64_t>(Variable_15021_BuffID));
    }
    return node96;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15021, 115) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 91, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(15021, 115) {
    auto node115 = GET_SKILL_NODE(115, PhaseNode_If);
    if (node115 == nullptr) {
        node115 = new PhaseNode_If(115, phase);
        CALL_REGISTER_SKILL_NODE(15021, 115, node115)
    }
    if (noInit == true) {
        return node115;
    }
    auto variables = node115->getVariables();
    if (variables != nullptr) {
        node115->setCondition(variables->getVariable<bool>(Variable_15021_IsTrigger));
    }
    return node115;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(15021, 119) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_SetBool::TRIGGER_DONE, 96, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(15021, 119) {
    auto node119 = GET_SKILL_NODE(119, PhaseNode_SetBool);
    if (node119 == nullptr) {
        node119 = new PhaseNode_SetBool(119, phase);
        node119->setName("IsTrigger");
        node119->setValue(true);
        CALL_REGISTER_SKILL_NODE(15021, 119, node119)
    }
    if (noInit == true) {
        return node119;
    }
    return node119;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(15021, 150) {
}

REGISTER_CREATE_SKILL_NODE(15021, 150) {
    auto node150 = GET_SKILL_NODE(150, PhaseNode_SetUInt64);
    if (node150 == nullptr) {
        node150 = new PhaseNode_SetUInt64(150, phase);
        node150->setName("BuffID");
        node150->setValue(0U);
        CALL_REGISTER_SKILL_NODE(15021, 150, node150)
    }
    if (noInit == true) {
        return node150;
    }
    return node150;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 168) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 180, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 182, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 168) {
    auto node168 = GET_SKILL_NODE(168, PhaseNode_CreateTriggerNewPene);
    if (node168 == nullptr) {
        node168 = new PhaseNode_CreateTriggerNewPene(168, phase);
        node168->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node168->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node168->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node168->setOnHero(true);
        node168->setOnMinion(true);
        node168->setOnDestruct(false);
        node168->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(15021, 168, node168)
    }
    if (noInit == true) {
        return node168;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 != nullptr) node168->setColliderID(node50->getColliderID());
    return node168;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(15021, 169) {
}

REGISTER_CREATE_SKILL_NODE(15021, 169) {
    auto node169 = GET_SKILL_NODE(169, PhaseNode_TriggerCheck);
    if (node169 == nullptr) {
        node169 = new PhaseNode_TriggerCheck(169, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node169);
        
        CALL_REGISTER_SKILL_NODE(15021, 169, node169)
    }
    if (noInit == true) {
        return node169;
    }
    auto node178 = GET_SKILL_NODE(178, PhaseNode_CreateTriggerNewPene);
    if (node178 != nullptr) node169->setTrigger(0, node178->getTriggerID());
    return node169;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 170) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 171, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(15021, 170) {
    auto node170 = GET_SKILL_NODE(170, PhaseNode_ActorFilterNewPene);
    if (node170 == nullptr) {
        node170 = new PhaseNode_ActorFilterNewPene(170, phase);
        node170->setHero(true);
        node170->setMinion(true);
        node170->setDestruct(false);
        node170->setShield(false);
        node170->setTotalCount(1);
        node170->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(15021, 170, node170)
    }
    if (noInit == true) {
        return node170;
    }
    auto node174 = GET_SKILL_NODE(174, PhaseNode_CreateTriggerNewPene);
    if (node174 != nullptr) node170->setInput(node174->getOther());
    return node170;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(15021, 171) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 172, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 185, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 186, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 187, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(15021, 171) {
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetActorAttribute);
    if (node171 == nullptr) {
        node171 = new PhaseNode_GetActorAttribute(171, phase);
        node171->setTarget(0U);
        node171->setType({202});
        CALL_REGISTER_SKILL_NODE(15021, 171, node171)
    }
    if (noInit == true) {
        return node171;
    }
    return node171;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(15021, 172) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 12, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 172) {
    auto node172 = GET_SKILL_NODE(172, PhaseNode_AddSkillBuffs);
    if (node172 == nullptr) {
        node172 = new PhaseNode_AddSkillBuffs(172, phase);
        node172->setConfigID({250211,250212});
        CALL_REGISTER_SKILL_NODE(15021, 172, node172)
    }
    if (noInit == true) {
        return node172;
    }
    auto node170 = GET_SKILL_NODE(170, PhaseNode_ActorFilterNewPene);
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetActorAttribute);
    if (node170 != nullptr) node172->setTarget(node170->getOutput());
    if (node171 != nullptr) node172->setAttribute(node171->getAttribute());
    return node172;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(15021, 173) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 168, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 174, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(15021, 173) {
    auto node173 = GET_SKILL_NODE(173, PhaseNode_CompareFloat);
    if (node173 == nullptr) {
        node173 = new PhaseNode_CompareFloat(173, phase);
        node173->setA(.00f);
        node173->setB(.00f);
        CALL_REGISTER_SKILL_NODE(15021, 173, node173)
    }
    if (noInit == true) {
        return node173;
    }
    return node173;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 174) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 179, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 170, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 174) {
    auto node174 = GET_SKILL_NODE(174, PhaseNode_CreateTriggerNewPene);
    if (node174 == nullptr) {
        node174 = new PhaseNode_CreateTriggerNewPene(174, phase);
        node174->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node174->setTypeParams(0, .00f);
        node174->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node174->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node174->setOnHero(true);
        node174->setOnMinion(true);
        node174->setOnDestruct(false);
        node174->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(15021, 174, node174)
    }
    if (noInit == true) {
        return node174;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 != nullptr) node174->setColliderID(node50->getColliderID());
    return node174;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15021, 175) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_FALSE, 176, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_If::TRIGGER_TRUE, 173, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(15021, 175) {
    auto node175 = GET_SKILL_NODE(175, PhaseNode_If);
    if (node175 == nullptr) {
        node175 = new PhaseNode_If(175, phase);
        node175->setCondition(true);
        CALL_REGISTER_SKILL_NODE(15021, 175, node175)
    }
    if (noInit == true) {
        return node175;
    }
    return node175;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(15021, 176) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 178, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_CompareFloat::TRIGGER_LESS, 177, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(15021, 176) {
    auto node176 = GET_SKILL_NODE(176, PhaseNode_CompareFloat);
    if (node176 == nullptr) {
        node176 = new PhaseNode_CompareFloat(176, phase);
        node176->setA(.00f);
        node176->setB(.00f);
        CALL_REGISTER_SKILL_NODE(15021, 176, node176)
    }
    if (noInit == true) {
        return node176;
    }
    return node176;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 177) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 181, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 183, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 177) {
    auto node177 = GET_SKILL_NODE(177, PhaseNode_CreateTriggerNewPene);
    if (node177 == nullptr) {
        node177 = new PhaseNode_CreateTriggerNewPene(177, phase);
        node177->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::Tick);
        node177->setTypeParams(0, .00f);
        node177->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node177->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node177->setOnHero(true);
        node177->setOnMinion(true);
        node177->setOnDestruct(false);
        node177->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(15021, 177, node177)
    }
    if (noInit == true) {
        return node177;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 != nullptr) node177->setColliderID(node50->getColliderID());
    return node177;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 178) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 169, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 184, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 178) {
    auto node178 = GET_SKILL_NODE(178, PhaseNode_CreateTriggerNewPene);
    if (node178 == nullptr) {
        node178 = new PhaseNode_CreateTriggerNewPene(178, phase);
        node178->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node178->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node178->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Friend);
        node178->setOnHero(true);
        node178->setOnMinion(true);
        node178->setOnDestruct(false);
        node178->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(15021, 178, node178)
    }
    if (noInit == true) {
        return node178;
    }
    auto node50 = GET_SKILL_NODE(50, PhaseNode_SpawnCollider);
    if (node50 != nullptr) node178->setColliderID(node50->getColliderID());
    return node178;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(15021, 179) {
}

REGISTER_CREATE_SKILL_NODE(15021, 179) {
    auto node179 = GET_SKILL_NODE(179, PhaseNode_TriggerCheck);
    if (node179 == nullptr) {
        node179 = new PhaseNode_TriggerCheck(179, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node179);
        
        CALL_REGISTER_SKILL_NODE(15021, 179, node179)
    }
    if (noInit == true) {
        return node179;
    }
    auto node174 = GET_SKILL_NODE(174, PhaseNode_CreateTriggerNewPene);
    if (node174 != nullptr) node179->setTrigger(0, node174->getTriggerID());
    return node179;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(15021, 180) {
}

REGISTER_CREATE_SKILL_NODE(15021, 180) {
    auto node180 = GET_SKILL_NODE(180, PhaseNode_TriggerCheck);
    if (node180 == nullptr) {
        node180 = new PhaseNode_TriggerCheck(180, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node180);
        
        CALL_REGISTER_SKILL_NODE(15021, 180, node180)
    }
    if (noInit == true) {
        return node180;
    }
    auto node168 = GET_SKILL_NODE(168, PhaseNode_CreateTriggerNewPene);
    if (node168 != nullptr) node180->setTrigger(0, node168->getTriggerID());
    return node180;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(15021, 181) {
}

REGISTER_CREATE_SKILL_NODE(15021, 181) {
    auto node181 = GET_SKILL_NODE(181, PhaseNode_TriggerCheck);
    if (node181 == nullptr) {
        node181 = new PhaseNode_TriggerCheck(181, phase);
        auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
        if (node2 != nullptr) node2->addTriggerCheck(node181);
        
        CALL_REGISTER_SKILL_NODE(15021, 181, node181)
    }
    if (noInit == true) {
        return node181;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_CreateTriggerNewPene);
    if (node177 != nullptr) node181->setTrigger(0, node177->getTriggerID());
    return node181;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 182) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 171, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(15021, 182) {
    auto node182 = GET_SKILL_NODE(182, PhaseNode_ActorFilterNewPene);
    if (node182 == nullptr) {
        node182 = new PhaseNode_ActorFilterNewPene(182, phase);
        node182->setHero(true);
        node182->setMinion(true);
        node182->setDestruct(false);
        node182->setShield(false);
        node182->setTotalCount(1);
        node182->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(15021, 182, node182)
    }
    if (noInit == true) {
        return node182;
    }
    auto node168 = GET_SKILL_NODE(168, PhaseNode_CreateTriggerNewPene);
    if (node168 != nullptr) node182->setInput(node168->getOther());
    return node182;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 183) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 171, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(15021, 183) {
    auto node183 = GET_SKILL_NODE(183, PhaseNode_ActorFilterNewPene);
    if (node183 == nullptr) {
        node183 = new PhaseNode_ActorFilterNewPene(183, phase);
        node183->setHero(true);
        node183->setMinion(true);
        node183->setDestruct(false);
        node183->setShield(false);
        node183->setTotalCount(1);
        node183->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(15021, 183, node183)
    }
    if (noInit == true) {
        return node183;
    }
    auto node177 = GET_SKILL_NODE(177, PhaseNode_CreateTriggerNewPene);
    if (node177 != nullptr) node183->setInput(node177->getOther());
    return node183;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(15021, 184) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 171, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(15021, 184) {
    auto node184 = GET_SKILL_NODE(184, PhaseNode_ActorFilterNewPene);
    if (node184 == nullptr) {
        node184 = new PhaseNode_ActorFilterNewPene(184, phase);
        node184->setHero(true);
        node184->setMinion(true);
        node184->setDestruct(false);
        node184->setShield(false);
        node184->setTotalCount(1);
        node184->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(15021, 184, node184)
    }
    if (noInit == true) {
        return node184;
    }
    auto node178 = GET_SKILL_NODE(178, PhaseNode_CreateTriggerNewPene);
    if (node178 != nullptr) node184->setInput(node178->getOther());
    return node184;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(15021, 185) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 12, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_AddSkillBuffs);
    if (node185 == nullptr) {
        node185 = new PhaseNode_AddSkillBuffs(185, phase);
        node185->setConfigID({250211,250212});
        CALL_REGISTER_SKILL_NODE(15021, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    auto node182 = GET_SKILL_NODE(182, PhaseNode_ActorFilterNewPene);
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetActorAttribute);
    if (node182 != nullptr) node185->setTarget(node182->getOutput());
    if (node171 != nullptr) node185->setAttribute(node171->getAttribute());
    return node185;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(15021, 186) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 12, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 186) {
    auto node186 = GET_SKILL_NODE(186, PhaseNode_AddSkillBuffs);
    if (node186 == nullptr) {
        node186 = new PhaseNode_AddSkillBuffs(186, phase);
        node186->setConfigID({250211,250212});
        CALL_REGISTER_SKILL_NODE(15021, 186, node186)
    }
    if (noInit == true) {
        return node186;
    }
    auto node183 = GET_SKILL_NODE(183, PhaseNode_ActorFilterNewPene);
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetActorAttribute);
    if (node183 != nullptr) node186->setTarget(node183->getOutput());
    if (node171 != nullptr) node186->setAttribute(node171->getAttribute());
    return node186;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(15021, 187) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuffs::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_AddSkillBuffs::TRIGGER_DONE, 12, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(15021, 187) {
    auto node187 = GET_SKILL_NODE(187, PhaseNode_AddSkillBuffs);
    if (node187 == nullptr) {
        node187 = new PhaseNode_AddSkillBuffs(187, phase);
        node187->setConfigID({250211,250212});
        CALL_REGISTER_SKILL_NODE(15021, 187, node187)
    }
    if (noInit == true) {
        return node187;
    }
    auto node184 = GET_SKILL_NODE(184, PhaseNode_ActorFilterNewPene);
    auto node171 = GET_SKILL_NODE(171, PhaseNode_GetActorAttribute);
    if (node184 != nullptr) node187->setTarget(node184->getOutput());
    if (node171 != nullptr) node187->setAttribute(node171->getAttribute());
    return node187;
}

//--------------------------------------------------------------------------------
// SkillCreator_15021
//
class SkillCreator_15021 : public SkillCreator {
public:
    SkillCreator_15021() {}
    virtual ~SkillCreator_15021() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_15021

//--------------------------------------------------------------------------------
// SkillPhase_15021
//
class SkillPhase_15021 : public SkillPhase {
public:
    SkillPhase_15021(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_15021() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(15021, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(15021, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(15021, 3) // GetLocation
        CASE_CREATE_SKILL_NODE(15021, 4) // ResetCD
        CASE_CREATE_SKILL_NODE(15021, 5) // SpawnCollider
        CASE_CREATE_SKILL_NODE(15021, 6) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15021, 12) // DestroyCollider
        CASE_CREATE_SKILL_NODE(15021, 13) // Delay
        CASE_CREATE_SKILL_NODE(15021, 14) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15021, 15) // Delay
        CASE_CREATE_SKILL_NODE(15021, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15021, 17) // Delay
        CASE_CREATE_SKILL_NODE(15021, 18) // DestroyActor
        CASE_CREATE_SKILL_NODE(15021, 19) // EndPhase
        CASE_CREATE_SKILL_NODE(15021, 20) // SpawnCollider
        CASE_CREATE_SKILL_NODE(15021, 33) // Delay
        CASE_CREATE_SKILL_NODE(15021, 50) // SpawnCollider
        CASE_CREATE_SKILL_NODE(15021, 85) // Detect
        CASE_CREATE_SKILL_NODE(15021, 87) // EndPhase
        CASE_CREATE_SKILL_NODE(15021, 89) // Delay
        CASE_CREATE_SKILL_NODE(15021, 91) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(15021, 96) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(15021, 115) // If
        CASE_CREATE_SKILL_NODE(15021, 119) // SetBool
        CASE_CREATE_SKILL_NODE(15021, 150) // SetUInt64
        CASE_CREATE_SKILL_NODE(15021, 168) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(15021, 169) // TriggerCheck
        CASE_CREATE_SKILL_NODE(15021, 170) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(15021, 171) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(15021, 172) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(15021, 173) // CompareFloat
        CASE_CREATE_SKILL_NODE(15021, 174) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(15021, 175) // If
        CASE_CREATE_SKILL_NODE(15021, 176) // CompareFloat
        CASE_CREATE_SKILL_NODE(15021, 177) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(15021, 178) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(15021, 179) // TriggerCheck
        CASE_CREATE_SKILL_NODE(15021, 180) // TriggerCheck
        CASE_CREATE_SKILL_NODE(15021, 181) // TriggerCheck
        CASE_CREATE_SKILL_NODE(15021, 182) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(15021, 183) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(15021, 184) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(15021, 185) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(15021, 186) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(15021, 187) // AddSkillBuffs
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_15021

SkillLogic* SkillCreator_15021::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_15021_IsTrigger = logic->getVariables().setVariable<bool>("IsTrigger");
    Variable_15021_BuffID = logic->getVariables().setVariable<uint64_t>("BuffID", 0U);
    //创建阶段phase
    auto phase = new SkillPhase_15021(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 85);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_15021::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
