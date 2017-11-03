#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_removeskillbuff.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10214, 4) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 9, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10214, 4) {
    auto node4 = GET_SKILL_NODE(4, PhaseNode_Detect);
    if (node4 == nullptr) {
        node4 = new PhaseNode_Detect(4, phase);
        node4->setSelf(0U);
        node4->setEvent("");
        node4->setType(PhaseNode_Detect::Detect_Type::Divorce_Fight);
        node4->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10214, 4, node4)
    }
    if (noInit == true) {
        return node4;
    }
    return node4;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10214, 9) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 28, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10214, 9) {
    auto node9 = GET_SKILL_NODE(9, PhaseNode_AddSkillBuff);
    if (node9 == nullptr) {
        node9 = new PhaseNode_AddSkillBuff(9, phase);
        node9->setConfigID(102141);
        node9->setConfigIDs({});
        node9->setTarget(0U);
        node9->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10214, 9, node9)
    }
    if (noInit == true) {
        return node9;
    }
    return node9;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10214, 21) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_Detect::TRIGGER_ON, 23, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10214, 21) {
    auto node21 = GET_SKILL_NODE(21, PhaseNode_Detect);
    if (node21 == nullptr) {
        node21 = new PhaseNode_Detect(21, phase);
        node21->setSelf(0U);
        node21->setEvent("");
        node21->setType(PhaseNode_Detect::Detect_Type::Enter_Fight);
        node21->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10214, 21, node21)
    }
    if (noInit == true) {
        return node21;
    }
    return node21;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10214, 23) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 46, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10214, 23) {
    auto node23 = GET_SKILL_NODE(23, PhaseNode_RemoveSkillBuff);
    if (node23 == nullptr) {
        node23 = new PhaseNode_RemoveSkillBuff(23, phase);
        node23->setBuffID(0U);
        node23->setBuffIDs({});
        node23->setConfigID(102141);
        node23->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10214, 23, node23)
    }
    if (noInit == true) {
        return node23;
    }
    return node23;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10214, 28) {
}

REGISTER_CREATE_SKILL_NODE(10214, 28) {
    auto node28 = GET_SKILL_NODE(28, PhaseNode_PlayAnimation);
    if (node28 == nullptr) {
        node28 = new PhaseNode_PlayAnimation(28, phase);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node28->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node28->setTarget(0U);
        node28->setAnimation("");
        node28->setParameter("Run2");
        node28->setValue(true);
        CALL_REGISTER_SKILL_NODE(10214, 28, node28)
    }
    if (noInit == true) {
        return node28;
    }
    return node28;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10214, 46) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 49, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10214, 46) {
    auto node46 = GET_SKILL_NODE(46, PhaseNode_FindSkillBuff);
    if (node46 == nullptr) {
        node46 = new PhaseNode_FindSkillBuff(46, phase);
        node46->setSelfTarget(0U);
        node46->setDetectTarget(0U);
        node46->setConfigID(102126);
        CALL_REGISTER_SKILL_NODE(10214, 46, node46)
    }
    if (noInit == true) {
        return node46;
    }
    return node46;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10214, 49) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_FALSE, 55, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10214, 49) {
    auto node49 = GET_SKILL_NODE(49, PhaseNode_If);
    if (node49 == nullptr) {
        node49 = new PhaseNode_If(49, phase);
        CALL_REGISTER_SKILL_NODE(10214, 49, node49)
    }
    if (noInit == true) {
        return node49;
    }
    auto node46 = GET_SKILL_NODE(46, PhaseNode_FindSkillBuff);
    if (node46 != nullptr) node49->setCondition(node46->getResult());
    return node49;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10214, 55) {
}

REGISTER_CREATE_SKILL_NODE(10214, 55) {
    auto node55 = GET_SKILL_NODE(55, PhaseNode_PlayAnimation);
    if (node55 == nullptr) {
        node55 = new PhaseNode_PlayAnimation(55, phase);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node55->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node55->setTarget(0U);
        node55->setAnimation("");
        node55->setParameter("Run2");
        node55->setValue(false);
        CALL_REGISTER_SKILL_NODE(10214, 55, node55)
    }
    if (noInit == true) {
        return node55;
    }
    return node55;
}

//--------------------------------------------------------------------------------
// SkillCreator_10214
//
class SkillCreator_10214 : public SkillCreator {
public:
    SkillCreator_10214() {}
    virtual ~SkillCreator_10214() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10214

//--------------------------------------------------------------------------------
// SkillPhase_10214
//
class SkillPhase_10214 : public SkillPhase {
public:
    SkillPhase_10214(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10214() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10214, 4) // Detect
        CASE_CREATE_SKILL_NODE(10214, 9) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10214, 21) // Detect
        CASE_CREATE_SKILL_NODE(10214, 23) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10214, 28) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10214, 46) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10214, 49) // If
        CASE_CREATE_SKILL_NODE(10214, 55) // PlayAnimation
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10214

SkillLogic* SkillCreator_10214::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10214(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 4);
    phase->setDetectPhaseNode(1, 21);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10214::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
