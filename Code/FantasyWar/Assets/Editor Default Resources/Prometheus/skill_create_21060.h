#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_skillendnotify.h"
#include "skill_psnode_startphase.h"

namespace pvp {

//变量声明
uint64_t Variable_21060_EffectEnable = 0;
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(21060, 2) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_StartPhase::TRIGGER_START, 8, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21060, 2) {
    auto node2 = GET_SKILL_NODE(2, PhaseNode_StartPhase);
    if (node2 == nullptr) {
        node2 = new PhaseNode_StartPhase(2, phase);
        CALL_REGISTER_SKILL_NODE(21060, 2, node2)
    }
    if (noInit == true) {
        return node2;
    }
    return node2;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21060, 8) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlayAnimation::TRIGGER_DONE, 21, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 8) {
    auto node8 = GET_SKILL_NODE(8, PhaseNode_PlayAnimation);
    if (node8 == nullptr) {
        node8 = new PhaseNode_PlayAnimation(8, phase);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node8->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node8->setTarget(0U);
        node8->setAnimation("Skill4S1");
        node8->setParameter("");
        node8->setValue(false);
        CALL_REGISTER_SKILL_NODE(21060, 8, node8)
    }
    if (noInit == true) {
        return node8;
    }
    return node8;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21060, 11) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 27, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(21060, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_PlayEffect);
    if (node11 == nullptr) {
        node11 = new PhaseNode_PlayEffect(11, phase);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node11->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node11->setEffectID(210601);
        node11->setChangeColor(false);
        node11->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node11->getVars().reserve(3);
        node11->getVars().setVariable<float>(0, .00f);
        node11->getVars().setVariable<float>(1, .00f);
        node11->getVars().setVariable<float>(2, .00f);
        node11->setRotation(.00f);
        node11->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21060, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    auto node21 = GET_SKILL_NODE(21, PhaseNode_GetLocation);
    if (node21 != nullptr) node11->getVars().setVariable<float>(0, node21->getX());
    if (node21 != nullptr) node11->getVars().setVariable<float>(1, node21->getY());
    return node11;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21060, 15) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Delay::TRIGGER_DONE, 45, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 15) {
    auto node15 = GET_SKILL_NODE(15, PhaseNode_Delay);
    if (node15 == nullptr) {
        node15 = new PhaseNode_Delay(15, phase);
        node15->setTime(1.40f);
        CALL_REGISTER_SKILL_NODE(21060, 15, node15)
    }
    if (noInit == true) {
        return node15;
    }
    return node15;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(21060, 17) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Disable::TRIGGER_DONE, 15, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21060, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Disable);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Disable(17, phase);
        node17->setTarget(0U);
        node17->setMove(true);
        node17->setSkill(true);
        node17->setShoot(true);
        node17->setTime(1.40f);
        node17->setRotate(true);
        CALL_REGISTER_SKILL_NODE(21060, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(21060, 21) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 11, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_GetLocation);
    if (node21 == nullptr) {
        node21 = new PhaseNode_GetLocation(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node21->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(21060, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(21060, 27) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_PlaySound::TRIGGER_DONE, 17, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 27) {
    auto node27 = GET_SKILL_NODE(27, PhaseNode_PlaySound);
    if (node27 == nullptr) {
        node27 = new PhaseNode_PlaySound(27, phase);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node27->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node27->setSoundID("SE_Boss2106_Birth");
        node27->setTarget(0U);
        node27->setUsePos(false);
        node27->setPosX(.00f);
        node27->setPosY(.00f);
        node27->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(21060, 27, node27)
    }
    if (noInit == true) {
        return node27;
    }
    return node27;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(21060, 36) {
}

REGISTER_CREATE_SKILL_NODE(21060, 36) {
    auto node36 = GET_SKILL_NODE(36, PhaseNode_PlayAnimation);
    if (node36 == nullptr) {
        node36 = new PhaseNode_PlayAnimation(36, phase);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node36->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node36->setTarget(0U);
        node36->setAnimation("Idle");
        node36->setParameter("");
        node36->setValue(false);
        CALL_REGISTER_SKILL_NODE(21060, 36, node36)
    }
    if (noInit == true) {
        return node36;
    }
    return node36;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(21060, 37) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayEffect::TRIGGER_DONE, 42, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(21060, 37) {
    auto node37 = GET_SKILL_NODE(37, PhaseNode_PlayEffect);
    if (node37 == nullptr) {
        node37 = new PhaseNode_PlayEffect(37, phase);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node37->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node37->setEffectID(210000);
        node37->setChangeColor(false);
        node37->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node37->getVars().reserve(5);
        node37->getVars().setVariable<uint64_t>(0, 0U);
        node37->getVars().setVariable<std::string>(1, "Hit");
        node37->getVars().setVariable<float>(2, .00f);
        node37->getVars().setVariable<float>(3, .00f);
        node37->getVars().setVariable<float>(4, .00f);
        node37->setRotation(.00f);
        node37->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(21060, 37, node37)
    }
    if (noInit == true) {
        return node37;
    }
    return node37;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(21060, 39) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_If::TRIGGER_TRUE, 41, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21060, 39) {
    auto node39 = GET_SKILL_NODE(39, PhaseNode_If);
    if (node39 == nullptr) {
        node39 = new PhaseNode_If(39, phase);
        CALL_REGISTER_SKILL_NODE(21060, 39, node39)
    }
    if (noInit == true) {
        return node39;
    }
    auto variables = node39->getVariables();
    if (variables != nullptr) {
        node39->setCondition(variables->getVariable<bool>(Variable_21060_EffectEnable));
    }
    return node39;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21060, 41) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_SetBool::TRIGGER_DONE, 37, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 41) {
    auto node41 = GET_SKILL_NODE(41, PhaseNode_SetBool);
    if (node41 == nullptr) {
        node41 = new PhaseNode_SetBool(41, phase);
        node41->setName("EffectEnable");
        node41->setValue(false);
        CALL_REGISTER_SKILL_NODE(21060, 41, node41)
    }
    if (noInit == true) {
        return node41;
    }
    return node41;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(21060, 42) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 43, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(21060, 42) {
    auto node42 = GET_SKILL_NODE(42, PhaseNode_Delay);
    if (node42 == nullptr) {
        node42 = new PhaseNode_Delay(42, phase);
        node42->setTime(.00f);
        CALL_REGISTER_SKILL_NODE(21060, 42, node42)
    }
    if (noInit == true) {
        return node42;
    }
    return node42;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(21060, 43) {
}

REGISTER_CREATE_SKILL_NODE(21060, 43) {
    auto node43 = GET_SKILL_NODE(43, PhaseNode_SetBool);
    if (node43 == nullptr) {
        node43 = new PhaseNode_SetBool(43, phase);
        node43->setName("EffectEnable");
        node43->setValue(true);
        CALL_REGISTER_SKILL_NODE(21060, 43, node43)
    }
    if (noInit == true) {
        return node43;
    }
    return node43;
}
//--------------------------------------------------------------------------------
// SkillEndNotify
//
REGISTER_REGISTER_SKILL_NODE(21060, 44) {
    pnode->resizeTrigger(PhaseNode_SkillEndNotify::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SkillEndNotify::TRIGGER_DONE, 36, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(21060, 44) {
    auto node44 = GET_SKILL_NODE(44, PhaseNode_SkillEndNotify);
    if (node44 == nullptr) {
        node44 = new PhaseNode_SkillEndNotify(44, phase);
        node44->setReturnType(true);
        CALL_REGISTER_SKILL_NODE(21060, 44, node44)
    }
    if (noInit == true) {
        return node44;
    }
    return node44;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(21060, 45) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SkillEndNotify>(PhaseNode_RaiseEvent::TRIGGER_DONE, 44, PhaseNode_SkillEndNotify::FUNC_DO, &PhaseNode_SkillEndNotify::Do);
}

REGISTER_CREATE_SKILL_NODE(21060, 45) {
    auto node45 = GET_SKILL_NODE(45, PhaseNode_RaiseEvent);
    if (node45 == nullptr) {
        node45 = new PhaseNode_RaiseEvent(45, phase);
        node45->setEvent("GetDamage");
        node45->setTarget(0U);
        node45->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node45->setTypeParams(0, 0);
        node45->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(21060, 45, node45)
    }
    if (noInit == true) {
        return node45;
    }
    return node45;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(21060, 46) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_Detect::TRIGGER_ON, 39, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(21060, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_Detect);
    if (node46 == nullptr) {
        node46 = new PhaseNode_Detect(46, phase);
        node46->setSelf(0U);
        node46->setEvent("GetDamage");
        node46->setType(PhaseNode_Detect::Detect_Type::Damage);
        node46->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(21060, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}

//--------------------------------------------------------------------------------
// SkillCreator_21060
//
class SkillCreator_21060 : public SkillCreator {
public:
    SkillCreator_21060() {}
    virtual ~SkillCreator_21060() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_21060

//--------------------------------------------------------------------------------
// SkillPhase_21060
//
class SkillPhase_21060 : public SkillPhase {
public:
    SkillPhase_21060(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_21060() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(21060, 2) // StartPhase
        CASE_CREATE_SKILL_NODE(21060, 8) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21060, 11) // PlayEffect
        CASE_CREATE_SKILL_NODE(21060, 15) // Delay
        CASE_CREATE_SKILL_NODE(21060, 17) // Disable
        CASE_CREATE_SKILL_NODE(21060, 21) // GetLocation
        CASE_CREATE_SKILL_NODE(21060, 27) // PlaySound
        CASE_CREATE_SKILL_NODE(21060, 36) // PlayAnimation
        CASE_CREATE_SKILL_NODE(21060, 37) // PlayEffect
        CASE_CREATE_SKILL_NODE(21060, 39) // If
        CASE_CREATE_SKILL_NODE(21060, 41) // SetBool
        CASE_CREATE_SKILL_NODE(21060, 42) // Delay
        CASE_CREATE_SKILL_NODE(21060, 43) // SetBool
        CASE_CREATE_SKILL_NODE(21060, 44) // SkillEndNotify
        CASE_CREATE_SKILL_NODE(21060, 45) // RaiseEvent
        CASE_CREATE_SKILL_NODE(21060, 46) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_21060

SkillLogic* SkillCreator_21060::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_21060_EffectEnable = logic->getVariables().setVariable<bool>("EffectEnable", true);
    //创建阶段phase
    auto phase = new SkillPhase_21060(1, logic, 2);
    //设置phase执行器
    phase->setRunPhaseNode(1, 2);
    phase->setDetectPhaseNode(2, 46);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_21060::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
