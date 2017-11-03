#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_15051_HurtState = 0;
uint64_t Variable_15051_HurtEnable = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(15051, 83) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_StartPhase::TRIGGER_START, 92, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(15051, 83) {
    auto node83 = GET_SKILL_NODE(83, PhaseNode_StartPhase);
    if (node83 == nullptr) {
        node83 = new PhaseNode_StartPhase(83, phase);
        CALL_REGISTER_SKILL_NODE(15051, 83, node83)
    }
    if (noInit == true) {
        return node83;
    }
    return node83;
}
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(15051, 85) {
}

REGISTER_CREATE_SKILL_NODE(15051, 85) {
    auto node85 = GET_SKILL_NODE(85, PhaseNode_TriggerUpdate);
    if (node85 == nullptr) {
        node85 = new PhaseNode_TriggerUpdate(85, phase);
        CALL_REGISTER_SKILL_NODE(15051, 85, node85)
    }
    if (noInit == true) {
        return node85;
    }
    return node85;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(15051, 88) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 104, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15051, 88) {
    auto node88 = GET_SKILL_NODE(88, PhaseNode_Detect);
    if (node88 == nullptr) {
        node88 = new PhaseNode_Detect(88, phase);
        node88->setSelf(0U);
        node88->setEvent("Hurt");
        node88->setType(PhaseNode_Detect::Detect_Type::Damage);
        node88->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(15051, 88, node88)
    }
    if (noInit == true) {
        return node88;
    }
    return node88;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(15051, 90) {
}

REGISTER_CREATE_SKILL_NODE(15051, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_SkillEndNotify);
    if (node90 == nullptr) {
        node90 = new PhaseNode_SkillEndNotify(90, phase);
        node90->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(15051, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(15051, 92) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 90, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(15051, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_RaiseEvent);
    if (node92 == nullptr) {
        node92 = new PhaseNode_RaiseEvent(92, phase);
        node92->setEvent("Hurt");
        node92->setTarget(0U);
        node92->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node92->setTypeParams(0, 0);
        node92->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(15051, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    return node92;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15051, 94) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15051, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlayAnimation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlayAnimation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setTarget(0U);
        node94->setAnimation("Skill1S1");
        node94->setParameter("");
        node94->setValue(false);
        CALL_REGISTER_SKILL_NODE(15051, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15051, 98) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_FALSE, 118, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 94, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(15051, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_If);
    if (node98 == nullptr) {
        node98 = new PhaseNode_If(98, phase);
        CALL_REGISTER_SKILL_NODE(15051, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    auto variables = node98->getVariables();
    if (variables != nullptr) {
        node98->setCondition(variables->getVariable<bool>(Variable_15051_HurtState));
    }
    return node98;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15051, 104) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 124, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(15051, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_If);
    if (node104 == nullptr) {
        node104 = new PhaseNode_If(104, phase);
        CALL_REGISTER_SKILL_NODE(15051, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    auto variables = node104->getVariables();
    if (variables != nullptr) {
        node104->setCondition(variables->getVariable<bool>(Variable_15051_HurtEnable));
    }
    return node104;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(15051, 108) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 129, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(15051, 108) {
    auto node108 = GET_SKILL_NODE(108, PhaseNode_PlayEffect);
    if (node108 == nullptr) {
        node108 = new PhaseNode_PlayEffect(108, phase);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node108->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node108->setEffectID(1012);
        node108->setChangeColor(false);
        node108->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node108->getVars().reserve(6);
        node108->getVars().setVariable<uint64_t>(0, 0U);
        node108->getVars().setVariable<std::string>(1, "");
        node108->getVars().setVariable<float>(2, .00f);
        node108->getVars().setVariable<float>(3, .00f);
        node108->getVars().setVariable<float>(4, .00f);
        node108->getVars().setVariable<bool>(5, false);
        node108->setRotation(.00f);
        node108->setScale(.00f);
        CALL_REGISTER_SKILL_NODE(15051, 108, node108)
    }
    if (noInit == true) {
        return node108;
    }
    return node108;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(15051, 110) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_FALSE, 116, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 114, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(15051, 110) {
    auto node110 = GET_SKILL_NODE(110, PhaseNode_If);
    if (node110 == nullptr) {
        node110 = new PhaseNode_If(110, phase);
        CALL_REGISTER_SKILL_NODE(15051, 110, node110)
    }
    if (noInit == true) {
        return node110;
    }
    auto variables = node110->getVariables();
    if (variables != nullptr) {
        node110->setCondition(variables->getVariable<bool>(Variable_15051_HurtState));
    }
    return node110;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(15051, 114) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SetBool::TRIGGER_DONE, 120, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15051, 114) {
    auto node114 = GET_SKILL_NODE(114, PhaseNode_SetBool);
    if (node114 == nullptr) {
        node114 = new PhaseNode_SetBool(114, phase);
        node114->setName("HurtState");
        node114->setValue(false);
        CALL_REGISTER_SKILL_NODE(15051, 114, node114)
    }
    if (noInit == true) {
        return node114;
    }
    return node114;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(15051, 116) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_SetBool::TRIGGER_DONE, 120, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(15051, 116) {
    auto node116 = GET_SKILL_NODE(116, PhaseNode_SetBool);
    if (node116 == nullptr) {
        node116 = new PhaseNode_SetBool(116, phase);
        node116->setName("HurtState");
        node116->setValue(true);
        CALL_REGISTER_SKILL_NODE(15051, 116, node116)
    }
    if (noInit == true) {
        return node116;
    }
    return node116;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(15051, 118) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlayAnimation::TRIGGER_DONE, 110, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15051, 118) {
    auto node118 = GET_SKILL_NODE(118, PhaseNode_PlayAnimation);
    if (node118 == nullptr) {
        node118 = new PhaseNode_PlayAnimation(118, phase);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node118->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node118->setTarget(0U);
        node118->setAnimation("Skill1S2");
        node118->setParameter("");
        node118->setValue(false);
        CALL_REGISTER_SKILL_NODE(15051, 118, node118)
    }
    if (noInit == true) {
        return node118;
    }
    return node118;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(15051, 120) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 122, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(15051, 120) {
    auto node120 = GET_SKILL_NODE(120, PhaseNode_Delay);
    if (node120 == nullptr) {
        node120 = new PhaseNode_Delay(120, phase);
        node120->setTime(.15f);
        CALL_REGISTER_SKILL_NODE(15051, 120, node120)
    }
    if (noInit == true) {
        return node120;
    }
    return node120;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(15051, 122) {
}

REGISTER_CREATE_SKILL_NODE(15051, 122) {
    auto node122 = GET_SKILL_NODE(122, PhaseNode_SetBool);
    if (node122 == nullptr) {
        node122 = new PhaseNode_SetBool(122, phase);
        node122->setName("HurtEnable");
        node122->setValue(true);
        CALL_REGISTER_SKILL_NODE(15051, 122, node122)
    }
    if (noInit == true) {
        return node122;
    }
    return node122;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(15051, 124) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 108, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(15051, 124) {
    auto node124 = GET_SKILL_NODE(124, PhaseNode_SetBool);
    if (node124 == nullptr) {
        node124 = new PhaseNode_SetBool(124, phase);
        node124->setName("HurtEnable");
        node124->setValue(false);
        CALL_REGISTER_SKILL_NODE(15051, 124, node124)
    }
    if (noInit == true) {
        return node124;
    }
    return node124;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(15051, 129) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_PlaySound::TRIGGER_DONE, 98, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(15051, 129) {
    auto node129 = GET_SKILL_NODE(129, PhaseNode_PlaySound);
    if (node129 == nullptr) {
        node129 = new PhaseNode_PlaySound(129, phase);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node129->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node129->setSoundID("SE_Hit_Body");
        node129->setTarget(0U);
        node129->setUsePos(false);
        node129->setPosX(.00f);
        node129->setPosY(.00f);
        node129->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(15051, 129, node129)
    }
    if (noInit == true) {
        return node129;
    }
    return node129;
}

//--------------------------------------------------------------------------------
// SkillCreator_15051
//
class SkillCreator_15051 : public SkillCreator {
public:
    SkillCreator_15051() {}
    virtual ~SkillCreator_15051() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_15051

//--------------------------------------------------------------------------------
// SkillPhase_15051
//
class SkillPhase_15051 : public SkillPhase {
public:
    SkillPhase_15051(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_15051() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(15051, 83) // StartPhase
        CASE_CREATE_SKILL_NODE(15051, 85) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(15051, 88) // Detect
        CASE_CREATE_SKILL_NODE(15051, 90) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(15051, 92) // RaiseEvent
        CASE_CREATE_SKILL_NODE(15051, 94) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15051, 98) // If
        CASE_CREATE_SKILL_NODE(15051, 104) // If
        CASE_CREATE_SKILL_NODE(15051, 108) // PlayEffect
        CASE_CREATE_SKILL_NODE(15051, 110) // If
        CASE_CREATE_SKILL_NODE(15051, 114) // SetBool
        CASE_CREATE_SKILL_NODE(15051, 116) // SetBool
        CASE_CREATE_SKILL_NODE(15051, 118) // PlayAnimation
        CASE_CREATE_SKILL_NODE(15051, 120) // Delay
        CASE_CREATE_SKILL_NODE(15051, 122) // SetBool
        CASE_CREATE_SKILL_NODE(15051, 124) // SetBool
        CASE_CREATE_SKILL_NODE(15051, 129) // PlaySound
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_15051

SkillLogic* SkillCreator_15051::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_15051_HurtState = logic->getVariables().setVariable<bool>("HurtState");
    Variable_15051_HurtEnable = logic->getVariables().setVariable<bool>("HurtEnable", true);
    //创建阶段phase
    auto phase = new SkillPhase_15051(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 83);
    phase->setRunPhaseNode(2, 85);
    phase->setDetectPhaseNode(3, 88);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_15051::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
