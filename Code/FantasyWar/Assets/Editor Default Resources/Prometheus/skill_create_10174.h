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
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10174, 80) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 90, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10174, 80) {
    auto node80 = GET_SKILL_NODE(80, PhaseNode_Detect);
    if (node80 == nullptr) {
        node80 = new PhaseNode_Detect(80, phase);
        node80->setSelf(0U);
        node80->setEvent("");
        node80->setType(PhaseNode_Detect::Detect_Type::Start_Skill);
        node80->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10174, 80, node80)
    }
    if (noInit == true) {
        return node80;
    }
    return node80;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10174, 87) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 92, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10174, 87) {
    auto node87 = GET_SKILL_NODE(87, PhaseNode_FindSkillBuff);
    if (node87 == nullptr) {
        node87 = new PhaseNode_FindSkillBuff(87, phase);
        node87->setSelfTarget(0U);
        node87->setDetectTarget(0U);
        node87->setConfigID(101742);
        CALL_REGISTER_SKILL_NODE(10174, 87, node87)
    }
    if (noInit == true) {
        return node87;
    }
    return node87;
}
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10174, 90) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_TimeDown::TRIGGER_DONE, 87, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10174, 90) {
    auto node90 = GET_SKILL_NODE(90, PhaseNode_TimeDown);
    if (node90 == nullptr) {
        node90 = new PhaseNode_TimeDown(90, phase);
        node90->setTime(.50f);
        node90->setNum(24);
        node90->setIsImmediateFirst(false);
        CALL_REGISTER_SKILL_NODE(10174, 90, node90)
    }
    if (noInit == true) {
        return node90;
    }
    return node90;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10174, 92) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_FALSE, 96, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 94, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10174, 92) {
    auto node92 = GET_SKILL_NODE(92, PhaseNode_If);
    if (node92 == nullptr) {
        node92 = new PhaseNode_If(92, phase);
        CALL_REGISTER_SKILL_NODE(10174, 92, node92)
    }
    if (noInit == true) {
        return node92;
    }
    auto node87 = GET_SKILL_NODE(87, PhaseNode_FindSkillBuff);
    if (node87 != nullptr) node92->setCondition(node87->getResult());
    return node92;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10174, 94) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 104, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10174, 94) {
    auto node94 = GET_SKILL_NODE(94, PhaseNode_PlayAnimation);
    if (node94 == nullptr) {
        node94 = new PhaseNode_PlayAnimation(94, phase);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node94->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node94->setTarget(0U);
        node94->setAnimation("");
        node94->setParameter("Run2");
        node94->setValue(true);
        CALL_REGISTER_SKILL_NODE(10174, 94, node94)
    }
    if (noInit == true) {
        return node94;
    }
    return node94;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10174, 96) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_PlayAnimation::TRIGGER_DONE, 101, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10174, 96) {
    auto node96 = GET_SKILL_NODE(96, PhaseNode_PlayAnimation);
    if (node96 == nullptr) {
        node96 = new PhaseNode_PlayAnimation(96, phase);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node96->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node96->setTarget(0U);
        node96->setAnimation("");
        node96->setParameter("Run2");
        node96->setValue(false);
        CALL_REGISTER_SKILL_NODE(10174, 96, node96)
    }
    if (noInit == true) {
        return node96;
    }
    return node96;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10174, 98) {
}

REGISTER_CREATE_SKILL_NODE(10174, 98) {
    auto node98 = GET_SKILL_NODE(98, PhaseNode_AddSkillBuff);
    if (node98 == nullptr) {
        node98 = new PhaseNode_AddSkillBuff(98, phase);
        node98->setConfigID(101746);
        node98->setConfigIDs({});
        node98->setTarget(0U);
        node98->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10174, 98, node98)
    }
    if (noInit == true) {
        return node98;
    }
    return node98;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10174, 101) {
}

REGISTER_CREATE_SKILL_NODE(10174, 101) {
    auto node101 = GET_SKILL_NODE(101, PhaseNode_RemoveSkillBuff);
    if (node101 == nullptr) {
        node101 = new PhaseNode_RemoveSkillBuff(101, phase);
        node101->setBuffID(0U);
        node101->setBuffIDs({});
        node101->setConfigID(101746);
        node101->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10174, 101, node101)
    }
    if (noInit == true) {
        return node101;
    }
    return node101;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10174, 104) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 106, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10174, 104) {
    auto node104 = GET_SKILL_NODE(104, PhaseNode_FindSkillBuff);
    if (node104 == nullptr) {
        node104 = new PhaseNode_FindSkillBuff(104, phase);
        node104->setSelfTarget(0U);
        node104->setDetectTarget(0U);
        node104->setConfigID(101746);
        CALL_REGISTER_SKILL_NODE(10174, 104, node104)
    }
    if (noInit == true) {
        return node104;
    }
    return node104;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10174, 106) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 98, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10174, 106) {
    auto node106 = GET_SKILL_NODE(106, PhaseNode_If);
    if (node106 == nullptr) {
        node106 = new PhaseNode_If(106, phase);
        CALL_REGISTER_SKILL_NODE(10174, 106, node106)
    }
    if (noInit == true) {
        return node106;
    }
    auto node104 = GET_SKILL_NODE(104, PhaseNode_FindSkillBuff);
    if (node104 != nullptr) node106->setCondition(node104->getResult());
    return node106;
}

//--------------------------------------------------------------------------------
// SkillCreator_10174
//
class SkillCreator_10174 : public SkillCreator {
public:
    SkillCreator_10174() {}
    virtual ~SkillCreator_10174() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10174

//--------------------------------------------------------------------------------
// SkillPhase_10174
//
class SkillPhase_10174 : public SkillPhase {
public:
    SkillPhase_10174(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10174() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10174, 80) // Detect
        CASE_CREATE_SKILL_NODE(10174, 87) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10174, 90) // TimeDown
        CASE_CREATE_SKILL_NODE(10174, 92) // If
        CASE_CREATE_SKILL_NODE(10174, 94) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10174, 96) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10174, 98) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10174, 101) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10174, 104) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10174, 106) // If
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10174

SkillLogic* SkillCreator_10174::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //创建阶段phase
    auto phase = new SkillPhase_10174(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 80);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10174::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
