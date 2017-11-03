#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getrotation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_offsetcalculate.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_spawnprojectile.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21041, 1) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 122, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 1) {
    auto node1 = GET_SKILL_NODE(1, PhaseNode_StartPhase);
    if (node1 == nullptr) {
        node1 = new PhaseNode_StartPhase(1, phase);
        CALL_REGISTER_SKILL_NODE(21041, 1, node1)
    }
    if (noInit == true) {
        return node1;
    }
    return node1;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(21041, 2) {
}

REGISTER_CREATE_SKILL_NODE(21041, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_TriggerUpdate);
    if (node2 == nullptr) {
        node2 = new PhaseNode_TriggerUpdate(2, phase);
        CALL_REGISTER_SKILL_NODE(21041, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21041, 31) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Detect::TRIGGER_ON, 32, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21041, 31) {
    auto node31 = GET_SKILL_NODE(31, PhaseNode_Detect);
    if (node31 == nullptr) {
        node31 = new PhaseNode_Detect(31, phase);
        node31->setSelf(0U);
        node31->setEvent("");
        node31->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node31->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21041, 31, node31)
    }
    if (noInit == true) {
        return node31;
    }
    return node31;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21041, 32) {
}

REGISTER_CREATE_SKILL_NODE(21041, 32) {
    auto node32 = GET_SKILL_NODE(32, PhaseNode_EndPhase);
    if (node32 == nullptr) {
        node32 = new PhaseNode_EndPhase(32, phase);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node32->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21041, 32, node32)
    }
    if (noInit == true) {
        return node32;
    }
    return node32;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(21041, 100) {
}

REGISTER_CREATE_SKILL_NODE(21041, 100) {
    auto node100 = GET_SKILL_NODE(100, PhaseNode_EndPhase);
    if (node100 == nullptr) {
        node100 = new PhaseNode_EndPhase(100, phase);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(21041, 100, node100)
    }
    if (noInit == true) {
        return node100;
    }
    return node100;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21041, 107) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 111, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 107) {
    auto node107 = GET_SKILL_NODE(107, PhaseNode_SpawnProjectile);
    if (node107 == nullptr) {
        node107 = new PhaseNode_SpawnProjectile(107, phase);
        node107->setDataId(52104);
        node107->setEndPosX(.00f);
        node107->setEndPosY(.00f);
        node107->setEndPosZ(.00f);
        node107->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21041, 107, node107)
    }
    if (noInit == true) {
        return node107;
    }
    auto node128 = GET_SKILL_NODE(128, PhaseNode_OffsetCalculate);
    if (node128 != nullptr) node107->setPosX(node128->getOutPosX());
    if (node128 != nullptr) node107->setPosY(node128->getOutPosY());
    if (node128 != nullptr) node107->setPosZ(node128->getOutPosZ());
    if (node128 != nullptr) node107->setRotation(node128->getOutRotation());
    return node107;
}
//--------------------------------------------------------------------------------
// SpawnProjectile
//
REGISTER_REGISTER_SKILL_NODE(21041, 111) {
    pnode->resizeTrigger(PhaseNode_SpawnProjectile::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SpawnProjectile::TRIGGER_DONE, 132, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21041, 111) {
    auto node111 = GET_SKILL_NODE(111, PhaseNode_SpawnProjectile);
    if (node111 == nullptr) {
        node111 = new PhaseNode_SpawnProjectile(111, phase);
        node111->setDataId(52104);
        node111->setEndPosX(.00f);
        node111->setEndPosY(.00f);
        node111->setEndPosZ(.00f);
        node111->setMaxCount(0);
        CALL_REGISTER_SKILL_NODE(21041, 111, node111)
    }
    if (noInit == true) {
        return node111;
    }
    auto node131 = GET_SKILL_NODE(131, PhaseNode_OffsetCalculate);
    if (node131 != nullptr) node111->setPosX(node131->getOutPosX());
    if (node131 != nullptr) node111->setPosY(node131->getOutPosY());
    if (node131 != nullptr) node111->setPosZ(node131->getOutPosZ());
    if (node131 != nullptr) node111->setRotation(node131->getOutRotation());
    return node111;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(21041, 122) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 123, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21041, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_ResetCD);
    if (node122 == nullptr) {
        node122 = new PhaseNode_ResetCD(122, phase);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node122->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node122->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(21041, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21041, 123) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayAnimation::TRIGGER_DONE, 124, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21041, 123) {
    auto node123 = GET_SKILL_NODE(123, PhaseNode_PlayAnimation);
    if (node123 == nullptr) {
        node123 = new PhaseNode_PlayAnimation(123, phase);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node123->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node123->setTarget(0U);
        node123->setAnimation("Skill1S1");
        node123->setParameter("");
        node123->setValue(false);
        CALL_REGISTER_SKILL_NODE(21041, 123, node123)
    }
    if (noInit == true) {
        return node123;
    }
    return node123;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21041, 124) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 125, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21041, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_PlaySound);
    if (node124 == nullptr) {
        node124 = new PhaseNode_PlaySound(124, phase);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node124->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node124->setSoundID("SE_MON_Npc_Battery_Launch");
        node124->setTarget(0U);
        node124->setUsePos(false);
        node124->setPosX(.00f);
        node124->setPosY(.00f);
        node124->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21041, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21041, 125) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_Delay::TRIGGER_DONE, 126, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 125) {
    auto node125 = GET_SKILL_NODE(125, PhaseNode_Delay);
    if (node125 == nullptr) {
        node125 = new PhaseNode_Delay(125, phase);
        node125->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21041, 125, node125)
    }
    if (noInit == true) {
        return node125;
    }
    return node125;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21041, 126) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 127, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 126) {
    auto node126 = GET_SKILL_NODE(126, PhaseNode_GetLocation);
    if (node126 == nullptr) {
        node126 = new PhaseNode_GetLocation(126, phase);
        node126->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node126->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21041, 126, node126)
    }
    if (noInit == true) {
        return node126;
    }
    return node126;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21041, 127) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 128, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 127) {
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetRotation);
    if (node127 == nullptr) {
        node127 = new PhaseNode_GetRotation(127, phase);
        node127->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node127->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21041, 127, node127)
    }
    if (noInit == true) {
        return node127;
    }
    return node127;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21041, 128) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 129, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 128) {
    auto node128 = GET_SKILL_NODE(128, PhaseNode_OffsetCalculate);
    if (node128 == nullptr) {
        node128 = new PhaseNode_OffsetCalculate(128, phase);
        node128->setPosZ(.00f);
        node128->setOffsetX(-1.50f);
        node128->setOffsetY(.50f);
        node128->setOffsetZ(2.00f);
        node128->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21041, 128, node128)
    }
    if (noInit == true) {
        return node128;
    }
    auto node126 = GET_SKILL_NODE(126, PhaseNode_GetLocation);
    auto node127 = GET_SKILL_NODE(127, PhaseNode_GetRotation);
    if (node126 != nullptr) node128->setPosX(node126->getX());
    if (node126 != nullptr) node128->setPosY(node126->getY());
    if (node127 != nullptr) node128->setRotation(node127->getAngle());
    return node128;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21041, 129) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 130, PhaseNode_GetRotation::FUNC_DO, &PhaseNode_GetRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_GetLocation);
    if (node129 == nullptr) {
        node129 = new PhaseNode_GetLocation(129, phase);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node129->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21041, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}
//--------------------------------------------------------------------------------
// GetRotation
//
REGISTER_REGISTER_SKILL_NODE(21041, 130) {
    pnode->resizeTrigger(PhaseNode_GetRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_OffsetCalculate>(PhaseNode_GetRotation::TRIGGER_DONE, 131, PhaseNode_OffsetCalculate::FUNC_DO, &PhaseNode_OffsetCalculate::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 130) {
    auto node130 = GET_SKILL_NODE(130, PhaseNode_GetRotation);
    if (node130 == nullptr) {
        node130 = new PhaseNode_GetRotation(130, phase);
        node130->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node130->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21041, 130, node130)
    }
    if (noInit == true) {
        return node130;
    }
    return node130;
}
//--------------------------------------------------------------------------------
// OffsetCalculate
//
REGISTER_REGISTER_SKILL_NODE(21041, 131) {
    pnode->resizeTrigger(PhaseNode_OffsetCalculate::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnProjectile>(PhaseNode_OffsetCalculate::TRIGGER_DONE, 107, PhaseNode_SpawnProjectile::FUNC_DO, &PhaseNode_SpawnProjectile::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 131) {
    auto node131 = GET_SKILL_NODE(131, PhaseNode_OffsetCalculate);
    if (node131 == nullptr) {
        node131 = new PhaseNode_OffsetCalculate(131, phase);
        node131->setPosZ(.00f);
        node131->setOffsetX(1.50f);
        node131->setOffsetY(.50f);
        node131->setOffsetZ(2.00f);
        node131->setRotOffset(.00f);
        CALL_REGISTER_SKILL_NODE(21041, 131, node131)
    }
    if (noInit == true) {
        return node131;
    }
    auto node129 = GET_SKILL_NODE(129, PhaseNode_GetLocation);
    auto node130 = GET_SKILL_NODE(130, PhaseNode_GetRotation);
    if (node129 != nullptr) node131->setPosX(node129->getX());
    if (node129 != nullptr) node131->setPosY(node129->getY());
    if (node130 != nullptr) node131->setRotation(node130->getAngle());
    return node131;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21041, 132) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Delay::TRIGGER_DONE, 134, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21041, 132) {
    auto node132 = GET_SKILL_NODE(132, PhaseNode_Delay);
    if (node132 == nullptr) {
        node132 = new PhaseNode_Delay(132, phase);
        node132->setTime(.37f);
        CALL_REGISTER_SKILL_NODE(21041, 132, node132)
    }
    if (noInit == true) {
        return node132;
    }
    return node132;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21041, 133) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 100, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21041, 133) {
    auto node133 = GET_SKILL_NODE(133, PhaseNode_SkillEndNotify);
    if (node133 == nullptr) {
        node133 = new PhaseNode_SkillEndNotify(133, phase);
        node133->setReturnType(false);
        CALL_REGISTER_SKILL_NODE(21041, 133, node133)
    }
    if (noInit == true) {
        return node133;
    }
    return node133;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21041, 134) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_FALSE, 135, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_If::TRIGGER_TRUE, 133, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21041, 134) {
    auto node134 = GET_SKILL_NODE(134, PhaseNode_If);
    if (node134 == nullptr) {
        node134 = new PhaseNode_If(134, phase);
        node134->setCondition(false);
        CALL_REGISTER_SKILL_NODE(21041, 134, node134)
    }
    if (noInit == true) {
        return node134;
    }
    return node134;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21041, 135) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 100, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(21041, 135) {
    auto node135 = GET_SKILL_NODE(135, PhaseNode_SkillEndNotify);
    if (node135 == nullptr) {
        node135 = new PhaseNode_SkillEndNotify(135, phase);
        node135->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21041, 135, node135)
    }
    if (noInit == true) {
        return node135;
    }
    return node135;
}

//--------------------------------------------------------------------------------
// SkillCreator_21041
//
class SkillCreator_21041 : public SkillCreator {
public:
    SkillCreator_21041() {}
    virtual ~SkillCreator_21041() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21041

//--------------------------------------------------------------------------------
// SkillPhase_21041
//
class SkillPhase_21041 : public SkillPhase {
public:
    SkillPhase_21041(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21041() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21041, 1) // StartPhase
        CASE_CREATE_SKILL_NODE(21041, 2) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(21041, 31) // Detect
        CASE_CREATE_SKILL_NODE(21041, 32) // EndPhase
        CASE_CREATE_SKILL_NODE(21041, 100) // EndPhase
        CASE_CREATE_SKILL_NODE(21041, 107) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21041, 111) // SpawnProjectile
        CASE_CREATE_SKILL_NODE(21041, 122) // ResetCD
        CASE_CREATE_SKILL_NODE(21041, 123) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21041, 124) // PlaySound
        CASE_CREATE_SKILL_NODE(21041, 125) // Delay
        CASE_CREATE_SKILL_NODE(21041, 126) // GetLocation
        CASE_CREATE_SKILL_NODE(21041, 127) // GetRotation
        CASE_CREATE_SKILL_NODE(21041, 128) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21041, 129) // GetLocation
        CASE_CREATE_SKILL_NODE(21041, 130) // GetRotation
        CASE_CREATE_SKILL_NODE(21041, 131) // OffsetCalculate
        CASE_CREATE_SKILL_NODE(21041, 132) // Delay
        CASE_CREATE_SKILL_NODE(21041, 133) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21041, 134) // If
        CASE_CREATE_SKILL_NODE(21041, 135) // SkillEndNotify
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21041

SkillLogic* SkillCreator_21041::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_21041(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 1);
    phase->setRunPhaseNode(2, 2);
    phase->setDetectPhaseNode(3, 31);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21041::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
