#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_comparefloat.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
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
REGISTER_REGISTER_SKILL_NODE(21066, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 42, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21066, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21066, 3) {
}

REGISTER_CREATE_SKILL_NODE(21066, 3) {
    auto node3 = GET_SKILL_NODE(3, PhaseNode_TriggerUpdate);
    if (node3 == nullptr) {
        node3 = new PhaseNode_TriggerUpdate(3, phase);
        CALL_REGISTER_SKILL_NODE(21066, 3, node3)
    }
    if (noInit == true) {
        return node3;
    }
    return node3;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 4) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 46, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Delay);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Delay(4, phase);
        node4->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21066, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 5) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 15, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 5) {
    auto node5 = GET_SKILL_NODE(5, PhaseNode_PlayAnimation);
    if (node5 == nullptr) {
        node5 = new PhaseNode_PlayAnimation(5, phase);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node5->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node5->setTarget(0U);
        node5->setAnimation("Skill3S2");
        node5->setParameter("");
        node5->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 5, node5)
    }
    if (noInit == true) {
        return node5;
    }
    return node5;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 6) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 33, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 6) {
    auto node6 = GET_SKILL_NODE(6, PhaseNode_Delay);
    if (node6 == nullptr) {
        node6 = new PhaseNode_Delay(6, phase);
        node6->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21066, 6, node6)
    }
    if (noInit == true) {
        return node6;
    }
    return node6;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 55, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill3S3");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21066, 9) {
}

REGISTER_CREATE_SKILL_NODE(21066, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_EndPhase);
    if (node9 == nullptr) {
        node9 = new PhaseNode_EndPhase(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21066, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21066, 12) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 6, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 12) {
    auto node12 = GET_SKILL_NODE(12, PhaseNode_SpawnProjectile);
    if (node12 == nullptr) {
        node12 = new PhaseNode_SpawnProjectile(12, phase);
        node12->setDataId(52107);
        node12->setEndPosX(6.83f);
        node12->setEndPosY(9.67f);
        node12->setEndPosZ(.00f);
        node12->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21066, 12, node12)
    }
    if (noInit == true) {
        return node12;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node12->setPosX(node48->getOutPosX());
    if (node48 != nullptr) node12->setPosY(node48->getOutPosY());
    if (node48 != nullptr) node12->setPosZ(node48->getOutPosZ());
    if (node48 != nullptr) node12->setRotation(node48->getOutRotation());
    return node12;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 14) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 12, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 14) {
    auto node14 = GET_SKILL_NODE(14, PhaseNode_Delay);
    if (node14 == nullptr) {
        node14 = new PhaseNode_Delay(14, phase);
        node14->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21066, 14, node14)
    }
    if (noInit == true) {
        return node14;
    }
    return node14;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21066, 15) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 50, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21066, 15) {
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
        CALL_REGISTER_SKILL_NODE(21066, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 16) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 5, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 16) {
    auto node16 = GET_SKILL_NODE(16, PhaseNode_PlayAnimation);
    if (node16 == nullptr) {
        node16 = new PhaseNode_PlayAnimation(16, phase);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node16->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node16->setTarget(0U);
        node16->setAnimation("Idle");
        node16->setParameter("");
        node16->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 16, node16)
    }
    if (noInit == true) {
        return node16;
    }
    return node16;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 28) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 32, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_PlayAnimation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_PlayAnimation(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node28->setTarget(0U);
        node28->setAnimation("Skill3S2");
        node28->setParameter("");
        node28->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 29) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 40, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 29) {
    auto node29 = GET_SKILL_NODE(29, PhaseNode_Delay);
    if (node29 == nullptr) {
        node29 = new PhaseNode_Delay(29, phase);
        node29->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21066, 29, node29)
    }
    if (noInit == true) {
        return node29;
    }
    return node29;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21066, 30) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 29, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 30) {
    auto node30 = GET_SKILL_NODE(30, PhaseNode_SpawnProjectile);
    if (node30 == nullptr) {
        node30 = new PhaseNode_SpawnProjectile(30, phase);
        node30->setDataId(52107);
        node30->setEndPosX(8.25f);
        node30->setEndPosY(8.25f);
        node30->setEndPosZ(.00f);
        node30->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21066, 30, node30)
    }
    if (noInit == true) {
        return node30;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node30->setPosX(node48->getOutPosX());
    if (node48 != nullptr) node30->setPosY(node48->getOutPosY());
    if (node48 != nullptr) node30->setPosZ(node48->getOutPosZ());
    if (node48 != nullptr) node30->setRotation(node48->getOutRotation());
    return node30;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 31) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 30, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Delay);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Delay(31, phase);
        node31->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21066, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21066, 32) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 60, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21066, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_PlaySound);
    if (node32 == nullptr) {
        node32 = new PhaseNode_PlaySound(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node32->setSoundID("SE_Boss2106_ATK2");
        node32->setTarget(0U);
        node32->setUsePos(false);
        node32->setPosX(.00f);
        node32->setPosY(.00f);
        node32->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 33) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 28, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 33) {
    auto node33 = GET_SKILL_NODE(33, PhaseNode_PlayAnimation);
    if (node33 == nullptr) {
        node33 = new PhaseNode_PlayAnimation(33, phase);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node33->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node33->setTarget(0U);
        node33->setAnimation("Idle");
        node33->setParameter("");
        node33->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 33, node33)
    }
    if (noInit == true) {
        return node33;
    }
    return node33;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 35) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 39, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 35) {
    auto node35 = GET_SKILL_NODE(35, PhaseNode_PlayAnimation);
    if (node35 == nullptr) {
        node35 = new PhaseNode_PlayAnimation(35, phase);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node35->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node35->setTarget(0U);
        node35->setAnimation("Skill3S2");
        node35->setParameter("");
        node35->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 35, node35)
    }
    if (noInit == true) {
        return node35;
    }
    return node35;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 36) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_Delay);
    if (node36 == nullptr) {
        node36 = new PhaseNode_Delay(36, phase);
        node36->setTime(.60f);
        CALL_REGISTER_SKILL_NODE(21066, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21066, 37) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 36, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_SpawnProjectile);
    if (node37 == nullptr) {
        node37 = new PhaseNode_SpawnProjectile(37, phase);
        node37->setDataId(52107);
        node37->setEndPosX(9.66f);
        node37->setEndPosY(6.84f);
        node37->setEndPosZ(.00f);
        node37->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21066, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node37->setPosX(node48->getOutPosX());
    if (node48 != nullptr) node37->setPosY(node48->getOutPosY());
    if (node48 != nullptr) node37->setPosZ(node48->getOutPosZ());
    if (node48 != nullptr) node37->setRotation(node48->getOutRotation());
    return node37;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 38) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_Delay::TRIGGER_DONE, 37, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 38) {
    auto node38 = GET_SKILL_NODE(38, PhaseNode_Delay);
    if (node38 == nullptr) {
        node38 = new PhaseNode_Delay(38, phase);
        node38->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(21066, 38, node38)
    }
    if (noInit == true) {
        return node38;
    }
    return node38;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21066, 39) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 66, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21066, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_PlaySound);
    if (node39 == nullptr) {
        node39 = new PhaseNode_PlaySound(39, phase);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node39->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node39->setSoundID("SE_Boss2106_ATK2");
        node39->setTarget(0U);
        node39->setUsePos(false);
        node39->setPosX(.00f);
        node39->setPosY(.00f);
        node39->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    return node39;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 40) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 35, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 40) {
    auto node40 = GET_SKILL_NODE(40, PhaseNode_PlayAnimation);
    if (node40 == nullptr) {
        node40 = new PhaseNode_PlayAnimation(40, phase);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node40->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node40->setTarget(0U);
        node40->setAnimation("Idle");
        node40->setParameter("");
        node40->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 40, node40)
    }
    if (noInit == true) {
        return node40;
    }
    return node40;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21066, 42) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 43, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_ResetCD);
    if (node42 == nullptr) {
        node42 = new PhaseNode_ResetCD(42, phase);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node42->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node42->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21066, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21066, 43) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 44, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_PlayAnimation);
    if (node43 == nullptr) {
        node43 = new PhaseNode_PlayAnimation(43, phase);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node43->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node43->setTarget(0U);
        node43->setAnimation("Skill3S1");
        node43->setParameter("");
        node43->setValue(false);
        CALL_REGISTER_SKILL_NODE(21066, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21066, 44) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 45, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_PlaySound);
    if (node44 == nullptr) {
        node44 = new PhaseNode_PlaySound(44, phase);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node44->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node44->setSoundID("");
        node44->setTarget(0U);
        node44->setUsePos(false);
        node44->setPosX(.00f);
        node44->setPosY(.00f);
        node44->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 45) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 4, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_Delay);
    if (node45 == nullptr) {
        node45 = new PhaseNode_Delay(45, phase);
        node45->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21066, 46) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 47, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    if (node46 == nullptr) {
        node46 = new PhaseNode_GetLocation(46, phase);
        node46->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node46->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21066, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21066, 47) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 48, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 47) {
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetRotation);
    if (node47 == nullptr) {
        node47 = new PhaseNode_GetRotation(47, phase);
        node47->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node47->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21066, 47, node47)
    }
    if (noInit == true) {
        return node47;
    }
    return node47;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21066, 48) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 16, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21066, 48) {
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 == nullptr) {
        node48 = new PhaseNode_OffsetCalculate(48, phase);
        node48->setPosZ(.00f);
        node48->setOffsetX(.90f);
        node48->setOffsetY(-.50f);
        node48->setOffsetZ(3.20f);
        node48->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 48, node48)
    }
    if (noInit == true) {
        return node48;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_GetLocation);
    auto node47 = GET_SKILL_NODE(47, PhaseNode_GetRotation);
    if (node46 != nullptr) node48->setPosX(node46->getX());
    if (node46 != nullptr) node48->setPosY(node46->getY());
    if (node47 != nullptr) node48->setRotation(node47->getAngle());
    return node48;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 49) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 52, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_PlayEffect);
    if (node49 == nullptr) {
        node49 = new PhaseNode_PlayEffect(49, phase);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node49->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node49->setEffectID(210631);
        node49->setChangeColor(false);
        node49->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node49->getVars().reserve(5);
        node49->getVars().setVariable<uint64_t>(0, 0U);
        node49->getVars().setVariable<std::string>(1, "");
        node49->getVars().setVariable<float>(2, .00f);
        node49->getVars().setVariable<float>(3, .00f);
        node49->getVars().setVariable<float>(4, .00f);
        node49->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node49->getVars().setVariable<float>(2, node48->getOutPosX());
    if (node48 != nullptr) node49->getVars().setVariable<float>(3, node48->getOutPosY());
    if (node48 != nullptr) node49->setRotation(node48->getOutRotation());
    return node49;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21066, 50) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 51, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 49, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 50) {
    auto node50 = GET_SKILL_NODE(50, PhaseNode_If);
    if (node50 == nullptr) {
        node50 = new PhaseNode_If(50, phase);
        node50->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21066, 50, node50)
    }
    if (noInit == true) {
        return node50;
    }
    return node50;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 51) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 52, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 51) {
    auto node51 = GET_SKILL_NODE(51, PhaseNode_PlayEffect);
    if (node51 == nullptr) {
        node51 = new PhaseNode_PlayEffect(51, phase);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node51->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node51->setEffectID(210631);
        node51->setChangeColor(false);
        node51->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node51->getVars().reserve(3);
        node51->getVars().setVariable<float>(0, .00f);
        node51->getVars().setVariable<float>(1, .00f);
        node51->getVars().setVariable<float>(2, .00f);
        node51->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 51, node51)
    }
    if (noInit == true) {
        return node51;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node51->getVars().setVariable<float>(0, node48->getOutPosX());
    if (node48 != nullptr) node51->getVars().setVariable<float>(1, node48->getOutPosY());
    if (node48 != nullptr) node51->setRotation(node48->getOutRotation());
    return node51;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21066, 52) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 14, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 53, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 52) {
    auto node52 = GET_SKILL_NODE(52, PhaseNode_CompareFloat);
    if (node52 == nullptr) {
        node52 = new PhaseNode_CompareFloat(52, phase);
        node52->setA(.00f);
        node52->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 52, node52)
    }
    if (noInit == true) {
        return node52;
    }
    return node52;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 53) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 54, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 53) {
    auto node53 = GET_SKILL_NODE(53, PhaseNode_Delay);
    if (node53 == nullptr) {
        node53 = new PhaseNode_Delay(53, phase);
        node53->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 53, node53)
    }
    if (noInit == true) {
        return node53;
    }
    return node53;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 54) {
}

REGISTER_CREATE_SKILL_NODE(21066, 54) {
    auto node54 = GET_SKILL_NODE(54, PhaseNode_StopEffect);
    if (node54 == nullptr) {
        node54 = new PhaseNode_StopEffect(54, phase);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node54->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node54->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21066, 54, node54)
    }
    if (noInit == true) {
        return node54;
    }
    return node54;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 55) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 57, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21066, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_Delay);
    if (node55 == nullptr) {
        node55 = new PhaseNode_Delay(55, phase);
        node55->setTime(.50f);
        CALL_REGISTER_SKILL_NODE(21066, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21066, 56) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21066, 56) {
    auto node56 = GET_SKILL_NODE(56, PhaseNode_SkillEndNotify);
    if (node56 == nullptr) {
        node56 = new PhaseNode_SkillEndNotify(56, phase);
        node56->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21066, 56, node56)
    }
    if (noInit == true) {
        return node56;
    }
    return node56;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21066, 57) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 58, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 56, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_If);
    if (node57 == nullptr) {
        node57 = new PhaseNode_If(57, phase);
        node57->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21066, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21066, 58) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 9, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21066, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_SkillEndNotify);
    if (node58 == nullptr) {
        node58 = new PhaseNode_SkillEndNotify(58, phase);
        node58->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21066, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 59) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 62, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_PlayEffect);
    if (node59 == nullptr) {
        node59 = new PhaseNode_PlayEffect(59, phase);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node59->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node59->setEffectID(210631);
        node59->setChangeColor(false);
        node59->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node59->getVars().reserve(5);
        node59->getVars().setVariable<uint64_t>(0, 0U);
        node59->getVars().setVariable<std::string>(1, "");
        node59->getVars().setVariable<float>(2, .00f);
        node59->getVars().setVariable<float>(3, .00f);
        node59->getVars().setVariable<float>(4, .00f);
        node59->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node59->getVars().setVariable<float>(2, node48->getOutPosX());
    if (node48 != nullptr) node59->getVars().setVariable<float>(3, node48->getOutPosY());
    if (node48 != nullptr) node59->setRotation(node48->getOutRotation());
    return node59;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21066, 60) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 61, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 59, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_If);
    if (node60 == nullptr) {
        node60 = new PhaseNode_If(60, phase);
        node60->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21066, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    return node60;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 61) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 62, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_PlayEffect);
    if (node61 == nullptr) {
        node61 = new PhaseNode_PlayEffect(61, phase);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node61->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node61->setEffectID(210631);
        node61->setChangeColor(false);
        node61->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node61->getVars().reserve(3);
        node61->getVars().setVariable<float>(0, .00f);
        node61->getVars().setVariable<float>(1, .00f);
        node61->getVars().setVariable<float>(2, .00f);
        node61->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node61->getVars().setVariable<float>(0, node48->getOutPosX());
    if (node48 != nullptr) node61->getVars().setVariable<float>(1, node48->getOutPosY());
    if (node48 != nullptr) node61->setRotation(node48->getOutRotation());
    return node61;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21066, 62) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 31, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 63, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 62) {
    auto node62 = GET_SKILL_NODE(62, PhaseNode_CompareFloat);
    if (node62 == nullptr) {
        node62 = new PhaseNode_CompareFloat(62, phase);
        node62->setA(.00f);
        node62->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 62, node62)
    }
    if (noInit == true) {
        return node62;
    }
    return node62;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 63) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 64, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 63) {
    auto node63 = GET_SKILL_NODE(63, PhaseNode_Delay);
    if (node63 == nullptr) {
        node63 = new PhaseNode_Delay(63, phase);
        node63->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 63, node63)
    }
    if (noInit == true) {
        return node63;
    }
    return node63;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 64) {
}

REGISTER_CREATE_SKILL_NODE(21066, 64) {
    auto node64 = GET_SKILL_NODE(64, PhaseNode_StopEffect);
    if (node64 == nullptr) {
        node64 = new PhaseNode_StopEffect(64, phase);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node64->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node64->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21066, 64, node64)
    }
    if (noInit == true) {
        return node64;
    }
    return node64;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 65) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 68, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 65) {
    auto node65 = GET_SKILL_NODE(65, PhaseNode_PlayEffect);
    if (node65 == nullptr) {
        node65 = new PhaseNode_PlayEffect(65, phase);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node65->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node65->setEffectID(210631);
        node65->setChangeColor(false);
        node65->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node65->getVars().reserve(5);
        node65->getVars().setVariable<uint64_t>(0, 0U);
        node65->getVars().setVariable<std::string>(1, "");
        node65->getVars().setVariable<float>(2, .00f);
        node65->getVars().setVariable<float>(3, .00f);
        node65->getVars().setVariable<float>(4, .00f);
        node65->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 65, node65)
    }
    if (noInit == true) {
        return node65;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node65->getVars().setVariable<float>(2, node48->getOutPosX());
    if (node48 != nullptr) node65->getVars().setVariable<float>(3, node48->getOutPosY());
    if (node48 != nullptr) node65->setRotation(node48->getOutRotation());
    return node65;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21066, 66) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_FALSE, 67, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_If::TRIGGER_TRUE, 65, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 66) {
    auto node66 = GET_SKILL_NODE(66, PhaseNode_If);
    if (node66 == nullptr) {
        node66 = new PhaseNode_If(66, phase);
        node66->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21066, 66, node66)
    }
    if (noInit == true) {
        return node66;
    }
    return node66;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 67) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareFloat>(PhaseNode_PlayEffect::TRIGGER_DONE, 68, PhaseNode_CompareFloat::FUNC_COMPARE, &PhaseNode_CompareFloat::Compare);
}

REGISTER_CREATE_SKILL_NODE(21066, 67) {
    auto node67 = GET_SKILL_NODE(67, PhaseNode_PlayEffect);
    if (node67 == nullptr) {
        node67 = new PhaseNode_PlayEffect(67, phase);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node67->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node67->setEffectID(210631);
        node67->setChangeColor(false);
        node67->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node67->getVars().reserve(3);
        node67->getVars().setVariable<float>(0, .00f);
        node67->getVars().setVariable<float>(1, .00f);
        node67->getVars().setVariable<float>(2, .00f);
        node67->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21066, 67, node67)
    }
    if (noInit == true) {
        return node67;
    }
    auto node48 = GET_SKILL_NODE(48, PhaseNode_OffsetCalculate);
    if (node48 != nullptr) node67->getVars().setVariable<float>(0, node48->getOutPosX());
    if (node48 != nullptr) node67->getVars().setVariable<float>(1, node48->getOutPosY());
    if (node48 != nullptr) node67->setRotation(node48->getOutRotation());
    return node67;
}
//--------------------------------------------------------------------------------
// CompareFloat
//
REGISTER_REGISTER_SKILL_NODE(21066, 68) {
    pnode->resizeTrigger(PhaseNode_CompareFloat::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_EQUAL, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 38, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_CompareFloat::TRIGGER_LESS, 69, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21066, 68) {
    auto node68 = GET_SKILL_NODE(68, PhaseNode_CompareFloat);
    if (node68 == nullptr) {
        node68 = new PhaseNode_CompareFloat(68, phase);
        node68->setA(.00f);
        node68->setB(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 68, node68)
    }
    if (noInit == true) {
        return node68;
    }
    return node68;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21066, 69) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_Delay::TRIGGER_DONE, 70, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21066, 69) {
    auto node69 = GET_SKILL_NODE(69, PhaseNode_Delay);
    if (node69 == nullptr) {
        node69 = new PhaseNode_Delay(69, phase);
        node69->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21066, 69, node69)
    }
    if (noInit == true) {
        return node69;
    }
    return node69;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(21066, 70) {
}

REGISTER_CREATE_SKILL_NODE(21066, 70) {
    auto node70 = GET_SKILL_NODE(70, PhaseNode_StopEffect);
    if (node70 == nullptr) {
        node70 = new PhaseNode_StopEffect(70, phase);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node70->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node70->setEffectID(210631);
        CALL_REGISTER_SKILL_NODE(21066, 70, node70)
    }
    if (noInit == true) {
        return node70;
    }
    return node70;
}

//--------------------------------------------------------------------------------
// SkillCreator_21066
//
class SkillCreator_21066 : public SkillCreator {
public:
    SkillCreator_21066() {}
    virtual ~SkillCreator_21066() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21066

//--------------------------------------------------------------------------------
// SkillPhase_21066
//
class SkillPhase_21066 : public SkillPhase {
public:
    SkillPhase_21066(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21066() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21066, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21066, 3) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21066, 4) // Delay
        CASE_CREATE_SKILL_NODE(21066, 5) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 6) // Delay
        CASE_CREATE_SKILL_NODE(21066, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 9) // EndPhase
        CASE_CREATE_SKILL_NODE(21066, 12) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21066, 14) // Delay
        CASE_CREATE_SKILL_NODE(21066, 15) // PlaySound
        CASE_CREATE_SKILL_NODE(21066, 16) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 28) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 29) // Delay
        CASE_CREATE_SKILL_NODE(21066, 30) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21066, 31) // Delay
        CASE_CREATE_SKILL_NODE(21066, 32) // PlaySound
        CASE_CREATE_SKILL_NODE(21066, 33) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 35) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 36) // Delay
        CASE_CREATE_SKILL_NODE(21066, 37) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21066, 38) // Delay
        CASE_CREATE_SKILL_NODE(21066, 39) // PlaySound
        CASE_CREATE_SKILL_NODE(21066, 40) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 42) // ResetCD
        CASE_CREATE_SKILL_NODE(21066, 43) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21066, 44) // PlaySound
        CASE_CREATE_SKILL_NODE(21066, 45) // Delay
        CASE_CREATE_SKILL_NODE(21066, 46) // GetLocation
        CASE_CREATE_SKILL_NODE(21066, 47) // GetRotation
        CASE_CREATE_SKILL_NODE(21066, 48) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21066, 49) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 50) // If
        CASE_CREATE_SKILL_NODE(21066, 51) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 52) // CompareFloat
        CASE_CREATE_SKILL_NODE(21066, 53) // Delay
        CASE_CREATE_SKILL_NODE(21066, 54) // StopEffect
        CASE_CREATE_SKILL_NODE(21066, 55) // Delay
        CASE_CREATE_SKILL_NODE(21066, 56) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21066, 57) // If
        CASE_CREATE_SKILL_NODE(21066, 58) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21066, 59) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 60) // If
        CASE_CREATE_SKILL_NODE(21066, 61) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 62) // CompareFloat
        CASE_CREATE_SKILL_NODE(21066, 63) // Delay
        CASE_CREATE_SKILL_NODE(21066, 64) // StopEffect
        CASE_CREATE_SKILL_NODE(21066, 65) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 66) // If
        CASE_CREATE_SKILL_NODE(21066, 67) // PlayEffect
        CASE_CREATE_SKILL_NODE(21066, 68) // CompareFloat
        CASE_CREATE_SKILL_NODE(21066, 69) // Delay
        CASE_CREATE_SKILL_NODE(21066, 70) // StopEffect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21066

SkillLogic* SkillCreator_21066::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21066(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setRunPhaseNode(2, 3);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21066::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
