#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_getbuffattribute.h"
#include "skill_psnode_intoperation.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_resetcd.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10284, 4) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_Detect::TRIGGER_ON, 57, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10284, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Detect);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Detect(4, phase);
        node4->setSelf(0U);
        node4->setEvent("");
        node4->setType(PhaseNode_Detect::Detect_Type::Divorce_Fight);
        node4->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10284, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10284, 9) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 11, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10284, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_PlayAnimation);
    if (node9 == nullptr) {
        node9 = new PhaseNode_PlayAnimation(9, phase);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node9->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node9->setTarget(0U);
        node9->setAnimation("Skill4S1");
        node9->setParameter("SkillArmBusy");
        node9->setValue(true);
        CALL_REGISTER_SKILL_NODE(10284, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10284, 11) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 23, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10284, 11) {
    auto node11 = GET_SKILL_NODE(11, PhaseNode_AddSkillBuff);
    if (node11 == nullptr) {
        node11 = new PhaseNode_AddSkillBuff(11, phase);
        node11->setConfigID(102841);
        node11->setConfigIDs({});
        node11->setTarget(0U);
        node11->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10284, 11, node11)
    }
    if (noInit == true) {
        return node11;
    }
    return node11;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10284, 13) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 9, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10284, 13) {
    auto node13 = GET_SKILL_NODE(13, PhaseNode_ResetCD);
    if (node13 == nullptr) {
        node13 = new PhaseNode_ResetCD(13, phase);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node13->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node13->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10284, 13, node13)
    }
    if (noInit == true) {
        return node13;
    }
    return node13;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10284, 17) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_Delay::TRIGGER_DONE, 21, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10284, 17) {
    auto node17 = GET_SKILL_NODE(17, PhaseNode_Delay);
    if (node17 == nullptr) {
        node17 = new PhaseNode_Delay(17, phase);
        node17->setTime(1.30f);
        CALL_REGISTER_SKILL_NODE(10284, 17, node17)
    }
    if (noInit == true) {
        return node17;
    }
    return node17;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10284, 21) {
}

REGISTER_CREATE_SKILL_NODE(10284, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_PlayAnimation);
    if (node21 == nullptr) {
        node21 = new PhaseNode_PlayAnimation(21, phase);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node21->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node21->setTarget(0U);
        node21->setAnimation("Idle");
        node21->setParameter("SkillArmBusy");
        node21->setValue(false);
        CALL_REGISTER_SKILL_NODE(10284, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10284, 23) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlaySound::TRIGGER_DONE, 17, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10284, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_PlaySound);
    if (node23 == nullptr) {
        node23 = new PhaseNode_PlaySound(23, phase);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node23->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node23->setSoundID("SE_Hero107_SkillD_P1");
        node23->setTarget(0U);
        node23->setUsePos(false);
        node23->setPosX(.00f);
        node23->setPosY(.00f);
        node23->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10284, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10284, 57) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetBuffAttribute>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 58, PhaseNode_GetBuffAttribute::FUNC_DO, &PhaseNode_GetBuffAttribute::Do);
}

REGISTER_CREATE_SKILL_NODE(10284, 57) {
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetBuffAttribute);
    if (node57 == nullptr) {
        node57 = new PhaseNode_GetBuffAttribute(57, phase);
        node57->setTarget(0U);
        node57->setAttribute(44);
        CALL_REGISTER_SKILL_NODE(10284, 57, node57)
    }
    if (noInit == true) {
        return node57;
    }
    return node57;
}
//--------------------------------------------------------------------------------
// GetBuffAttribute
//
REGISTER_REGISTER_SKILL_NODE(10284, 58) {
    pnode->resizeTrigger(PhaseNode_GetBuffAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_GetBuffAttribute::TRIGGER_DONE, 59, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10284, 58) {
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetBuffAttribute);
    if (node58 == nullptr) {
        node58 = new PhaseNode_GetBuffAttribute(58, phase);
        node58->setTarget(0U);
        node58->setAttribute(2);
        CALL_REGISTER_SKILL_NODE(10284, 58, node58)
    }
    if (noInit == true) {
        return node58;
    }
    return node58;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10284, 59) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IntOperation>(PhaseNode_IntOperation::TRIGGER_DONE, 60, PhaseNode_IntOperation::FUNC_OPERATION, &PhaseNode_IntOperation::Operation);
}

REGISTER_CREATE_SKILL_NODE(10284, 59) {
    auto node59 = GET_SKILL_NODE(59, PhaseNode_IntOperation);
    if (node59 == nullptr) {
        node59 = new PhaseNode_IntOperation(59, phase);
        node59->setValue(100);
        node59->setMethod(PhaseNode_IntOperation::IntOperation_Method::Multi);
        CALL_REGISTER_SKILL_NODE(10284, 59, node59)
    }
    if (noInit == true) {
        return node59;
    }
    auto node57 = GET_SKILL_NODE(57, PhaseNode_GetBuffAttribute);
    if (node57 != nullptr) node59->setBase(node57->getValue());
    return node59;
}
//--------------------------------------------------------------------------------
// IntOperation
//
REGISTER_REGISTER_SKILL_NODE(10284, 60) {
    pnode->resizeTrigger(PhaseNode_IntOperation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CompareInt>(PhaseNode_IntOperation::TRIGGER_DONE, 61, PhaseNode_CompareInt::FUNC_COMPARE, &PhaseNode_CompareInt::Compare);
}

REGISTER_CREATE_SKILL_NODE(10284, 60) {
    auto node60 = GET_SKILL_NODE(60, PhaseNode_IntOperation);
    if (node60 == nullptr) {
        node60 = new PhaseNode_IntOperation(60, phase);
        node60->setMethod(PhaseNode_IntOperation::IntOperation_Method::Divis);
        CALL_REGISTER_SKILL_NODE(10284, 60, node60)
    }
    if (noInit == true) {
        return node60;
    }
    auto node59 = GET_SKILL_NODE(59, PhaseNode_IntOperation);
    auto node58 = GET_SKILL_NODE(58, PhaseNode_GetBuffAttribute);
    if (node59 != nullptr) node60->setBase(node59->getFinal());
    if (node58 != nullptr) node60->setValue(node58->getValue());
    return node60;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10284, 61) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_CompareInt::TRIGGER_LESS, 13, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10284, 61) {
    auto node61 = GET_SKILL_NODE(61, PhaseNode_CompareInt);
    if (node61 == nullptr) {
        node61 = new PhaseNode_CompareInt(61, phase);
        node61->setB(100);
        CALL_REGISTER_SKILL_NODE(10284, 61, node61)
    }
    if (noInit == true) {
        return node61;
    }
    auto node60 = GET_SKILL_NODE(60, PhaseNode_IntOperation);
    if (node60 != nullptr) node61->setA(node60->getFinal());
    return node61;
}

//--------------------------------------------------------------------------------
// SkillCreator_10284
//
class SkillCreator_10284 : public SkillCreator {
public:
    SkillCreator_10284() {}
    virtual ~SkillCreator_10284() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10284

//--------------------------------------------------------------------------------
// SkillPhase_10284
//
class SkillPhase_10284 : public SkillPhase {
public:
    SkillPhase_10284(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10284() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10284, 4) // Detect
        CASE_CREATE_SKILL_NODE(10284, 9) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10284, 11) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10284, 13) // ResetCD
        CASE_CREATE_SKILL_NODE(10284, 17) // Delay
        CASE_CREATE_SKILL_NODE(10284, 21) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10284, 23) // PlaySound
        CASE_CREATE_SKILL_NODE(10284, 57) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(10284, 58) // GetBuffAttribute
        CASE_CREATE_SKILL_NODE(10284, 59) // IntOperation
        CASE_CREATE_SKILL_NODE(10284, 60) // IntOperation
        CASE_CREATE_SKILL_NODE(10284, 61) // CompareInt
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10284

SkillLogic* SkillCreator_10284::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10284(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 4);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10284::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
