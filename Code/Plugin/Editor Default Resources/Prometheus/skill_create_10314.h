#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_compareint.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_findskillbuff.h"
#include "skill_psnode_if.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_removeskillbuff.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setint.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_timedown.h"

namespace pvp {

//变量声明
uint64_t Variable_10314_101341 = 0;
uint64_t Variable_10314_101342 = 0;
uint64_t Variable_10314_size = 0;
//--------------------------------------------------------------------------------
// TimeDown
//
REGISTER_REGISTER_SKILL_NODE(10314, 137) {
    pnode->resizeTrigger(PhaseNode_TimeDown::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_TimeDown::TRIGGER_DONE, 205, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 137) {
    auto node137 = GET_SKILL_NODE(137, PhaseNode_TimeDown);
    if (node137 == nullptr) {
        node137 = new PhaseNode_TimeDown(137, phase);
        node137->setTime(.50f);
        node137->setNum(24);
        node137->setIsImmediateFirst(true);
        CALL_REGISTER_SKILL_NODE(10314, 137, node137)
    }
    if (noInit == true) {
        return node137;
    }
    return node137;
}
//--------------------------------------------------------------------------------
// CompareInt
//
REGISTER_REGISTER_SKILL_NODE(10314, 145) {
    pnode->resizeTrigger(PhaseNode_CompareInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_CompareInt::TRIGGER_EQUAL, 153, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_CompareInt::TRIGGER_GREATER, 155, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_CompareInt::TRIGGER_LESS, 151, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 145) {
    auto node145 = GET_SKILL_NODE(145, PhaseNode_CompareInt);
    if (node145 == nullptr) {
        node145 = new PhaseNode_CompareInt(145, phase);
        node145->setB(2);
        CALL_REGISTER_SKILL_NODE(10314, 145, node145)
    }
    if (noInit == true) {
        return node145;
    }
    auto variables = node145->getVariables();
    if (variables != nullptr) {
        node145->setA(variables->getVariable<int32_t>(Variable_10314_101342));
    }
    return node145;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10314, 151) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_StopEffect::TRIGGER_DONE, 185, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 151) {
    auto node151 = GET_SKILL_NODE(151, PhaseNode_StopEffect);
    if (node151 == nullptr) {
        node151 = new PhaseNode_StopEffect(151, phase);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node151->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node151->setEffectID(103142);
        CALL_REGISTER_SKILL_NODE(10314, 151, node151)
    }
    if (noInit == true) {
        return node151;
    }
    return node151;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10314, 153) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_StopEffect::TRIGGER_DONE, 185, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 153) {
    auto node153 = GET_SKILL_NODE(153, PhaseNode_StopEffect);
    if (node153 == nullptr) {
        node153 = new PhaseNode_StopEffect(153, phase);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node153->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node153->setEffectID(103143);
        CALL_REGISTER_SKILL_NODE(10314, 153, node153)
    }
    if (noInit == true) {
        return node153;
    }
    return node153;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10314, 155) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_StopEffect::TRIGGER_DONE, 185, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 155) {
    auto node155 = GET_SKILL_NODE(155, PhaseNode_StopEffect);
    if (node155 == nullptr) {
        node155 = new PhaseNode_StopEffect(155, phase);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node155->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node155->setEffectID(103144);
        CALL_REGISTER_SKILL_NODE(10314, 155, node155)
    }
    if (noInit == true) {
        return node155;
    }
    return node155;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 185) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetInt>(PhaseNode_If::TRIGGER_TRUE, 191, PhaseNode_SetInt::FUNC_SET, &PhaseNode_SetInt::Set);
}

REGISTER_CREATE_SKILL_NODE(10314, 185) {
    auto node185 = GET_SKILL_NODE(185, PhaseNode_If);
    if (node185 == nullptr) {
        node185 = new PhaseNode_If(185, phase);
        CALL_REGISTER_SKILL_NODE(10314, 185, node185)
    }
    if (noInit == true) {
        return node185;
    }
    auto variables = node185->getVariables();
    if (variables != nullptr) {
        node185->setCondition(variables->getVariable<bool>(Variable_10314_size));
    }
    return node185;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10314, 189) {
}

REGISTER_CREATE_SKILL_NODE(10314, 189) {
    auto node189 = GET_SKILL_NODE(189, PhaseNode_SetBool);
    if (node189 == nullptr) {
        node189 = new PhaseNode_SetBool(189, phase);
        node189->setName("size");
        node189->setValue(false);
        CALL_REGISTER_SKILL_NODE(10314, 189, node189)
    }
    if (noInit == true) {
        return node189;
    }
    return node189;
}
//--------------------------------------------------------------------------------
// SetInt
//
REGISTER_REGISTER_SKILL_NODE(10314, 191) {
    pnode->resizeTrigger(PhaseNode_SetInt::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_SetInt::TRIGGER_DONE, 189, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10314, 191) {
    auto node191 = GET_SKILL_NODE(191, PhaseNode_SetInt);
    if (node191 == nullptr) {
        node191 = new PhaseNode_SetInt(191, phase);
        node191->setName("101342");
        node191->setValue(0);
        CALL_REGISTER_SKILL_NODE(10314, 191, node191)
    }
    if (noInit == true) {
        return node191;
    }
    return node191;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10314, 199) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 137, PhaseNode_TimeDown::FUNC_DO, &PhaseNode_TimeDown::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 199) {
    auto node199 = GET_SKILL_NODE(199, PhaseNode_Detect);
    if (node199 == nullptr) {
        node199 = new PhaseNode_Detect(199, phase);
        node199->setSelf(0U);
        node199->setEvent("");
        node199->setType(PhaseNode_Detect::Detect_Type::Start_Skill);
        node199->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10314, 199, node199)
    }
    if (noInit == true) {
        return node199;
    }
    return node199;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10314, 201) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TimeDown>(PhaseNode_Detect::TRIGGER_ON, 137, PhaseNode_TimeDown::FUNC_CANCEL, &PhaseNode_TimeDown::Cancel);
}

REGISTER_CREATE_SKILL_NODE(10314, 201) {
    auto node201 = GET_SKILL_NODE(201, PhaseNode_Detect);
    if (node201 == nullptr) {
        node201 = new PhaseNode_Detect(201, phase);
        node201->setSelf(0U);
        node201->setEvent("");
        node201->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node201->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10314, 201, node201)
    }
    if (noInit == true) {
        return node201;
    }
    return node201;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 204) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 206, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 222, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 204) {
    auto node204 = GET_SKILL_NODE(204, PhaseNode_If);
    if (node204 == nullptr) {
        node204 = new PhaseNode_If(204, phase);
        CALL_REGISTER_SKILL_NODE(10314, 204, node204)
    }
    if (noInit == true) {
        return node204;
    }
    auto node205 = GET_SKILL_NODE(205, PhaseNode_FindSkillBuff);
    if (node205 != nullptr) node204->setCondition(node205->getResult());
    return node204;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 205) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 204, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 205) {
    auto node205 = GET_SKILL_NODE(205, PhaseNode_FindSkillBuff);
    if (node205 == nullptr) {
        node205 = new PhaseNode_FindSkillBuff(205, phase);
        node205->setSelfTarget(0U);
        node205->setDetectTarget(0U);
        node205->setConfigID(103145);
        CALL_REGISTER_SKILL_NODE(10314, 205, node205)
    }
    if (noInit == true) {
        return node205;
    }
    return node205;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 206) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 208, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 206) {
    auto node206 = GET_SKILL_NODE(206, PhaseNode_FindSkillBuff);
    if (node206 == nullptr) {
        node206 = new PhaseNode_FindSkillBuff(206, phase);
        node206->setSelfTarget(0U);
        node206->setDetectTarget(0U);
        node206->setConfigID(103144);
        CALL_REGISTER_SKILL_NODE(10314, 206, node206)
    }
    if (noInit == true) {
        return node206;
    }
    return node206;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 207) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 209, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 207) {
    auto node207 = GET_SKILL_NODE(207, PhaseNode_FindSkillBuff);
    if (node207 == nullptr) {
        node207 = new PhaseNode_FindSkillBuff(207, phase);
        node207->setSelfTarget(0U);
        node207->setDetectTarget(0U);
        node207->setConfigID(103142);
        CALL_REGISTER_SKILL_NODE(10314, 207, node207)
    }
    if (noInit == true) {
        return node207;
    }
    return node207;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 208) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 207, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 218, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 208) {
    auto node208 = GET_SKILL_NODE(208, PhaseNode_If);
    if (node208 == nullptr) {
        node208 = new PhaseNode_If(208, phase);
        CALL_REGISTER_SKILL_NODE(10314, 208, node208)
    }
    if (noInit == true) {
        return node208;
    }
    auto node206 = GET_SKILL_NODE(206, PhaseNode_FindSkillBuff);
    if (node206 != nullptr) node208->setCondition(node206->getResult());
    return node208;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 209) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 245, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
    pnode->regTrigger<PhaseNode_FindSkillBuff>(PhaseNode_If::TRIGGER_TRUE, 220, PhaseNode_FindSkillBuff::FUNC_DO, &PhaseNode_FindSkillBuff::Do);
}

REGISTER_CREATE_SKILL_NODE(10314, 209) {
    auto node209 = GET_SKILL_NODE(209, PhaseNode_If);
    if (node209 == nullptr) {
        node209 = new PhaseNode_If(209, phase);
        CALL_REGISTER_SKILL_NODE(10314, 209, node209)
    }
    if (noInit == true) {
        return node209;
    }
    auto node207 = GET_SKILL_NODE(207, PhaseNode_FindSkillBuff);
    if (node207 != nullptr) node209->setCondition(node207->getResult());
    return node209;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 218) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 224, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 218) {
    auto node218 = GET_SKILL_NODE(218, PhaseNode_FindSkillBuff);
    if (node218 == nullptr) {
        node218 = new PhaseNode_FindSkillBuff(218, phase);
        node218->setSelfTarget(0U);
        node218->setDetectTarget(0U);
        node218->setConfigID(103147);
        CALL_REGISTER_SKILL_NODE(10314, 218, node218)
    }
    if (noInit == true) {
        return node218;
    }
    return node218;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 220) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 240, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 220) {
    auto node220 = GET_SKILL_NODE(220, PhaseNode_FindSkillBuff);
    if (node220 == nullptr) {
        node220 = new PhaseNode_FindSkillBuff(220, phase);
        node220->setSelfTarget(0U);
        node220->setDetectTarget(0U);
        node220->setConfigID(103146);
        CALL_REGISTER_SKILL_NODE(10314, 220, node220)
    }
    if (noInit == true) {
        return node220;
    }
    return node220;
}
//--------------------------------------------------------------------------------
// FindSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 222) {
    pnode->resizeTrigger(PhaseNode_FindSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_FindSkillBuff::TRIGGER_DONE, 230, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10314, 222) {
    auto node222 = GET_SKILL_NODE(222, PhaseNode_FindSkillBuff);
    if (node222 == nullptr) {
        node222 = new PhaseNode_FindSkillBuff(222, phase);
        node222->setSelfTarget(0U);
        node222->setDetectTarget(0U);
        node222->setConfigID(103148);
        CALL_REGISTER_SKILL_NODE(10314, 222, node222)
    }
    if (noInit == true) {
        return node222;
    }
    return node222;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 224) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 232, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10314, 224) {
    auto node224 = GET_SKILL_NODE(224, PhaseNode_If);
    if (node224 == nullptr) {
        node224 = new PhaseNode_If(224, phase);
        CALL_REGISTER_SKILL_NODE(10314, 224, node224)
    }
    if (noInit == true) {
        return node224;
    }
    auto node218 = GET_SKILL_NODE(218, PhaseNode_FindSkillBuff);
    if (node218 != nullptr) node224->setCondition(node218->getResult());
    return node224;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 226) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 238, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10314, 226) {
    auto node226 = GET_SKILL_NODE(226, PhaseNode_RemoveSkillBuff);
    if (node226 == nullptr) {
        node226 = new PhaseNode_RemoveSkillBuff(226, phase);
        node226->setBuffID(0U);
        node226->setBuffIDs({});
        node226->setConfigID(103147);
        node226->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 226, node226)
    }
    if (noInit == true) {
        return node226;
    }
    return node226;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 230) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 226, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10314, 230) {
    auto node230 = GET_SKILL_NODE(230, PhaseNode_If);
    if (node230 == nullptr) {
        node230 = new PhaseNode_If(230, phase);
        CALL_REGISTER_SKILL_NODE(10314, 230, node230)
    }
    if (noInit == true) {
        return node230;
    }
    auto node222 = GET_SKILL_NODE(222, PhaseNode_FindSkillBuff);
    if (node222 != nullptr) node230->setCondition(node222->getResult());
    return node230;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 232) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 236, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10314, 232) {
    auto node232 = GET_SKILL_NODE(232, PhaseNode_RemoveSkillBuff);
    if (node232 == nullptr) {
        node232 = new PhaseNode_RemoveSkillBuff(232, phase);
        node232->setBuffID(0U);
        node232->setBuffIDs({});
        node232->setConfigID(103146);
        node232->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 232, node232)
    }
    if (noInit == true) {
        return node232;
    }
    return node232;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 234) {
}

REGISTER_CREATE_SKILL_NODE(10314, 234) {
    auto node234 = GET_SKILL_NODE(234, PhaseNode_AddSkillBuff);
    if (node234 == nullptr) {
        node234 = new PhaseNode_AddSkillBuff(234, phase);
        node234->setConfigID(103148);
        node234->setConfigIDs({});
        node234->setTarget(0U);
        node234->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10314, 234, node234)
    }
    if (noInit == true) {
        return node234;
    }
    return node234;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 236) {
}

REGISTER_CREATE_SKILL_NODE(10314, 236) {
    auto node236 = GET_SKILL_NODE(236, PhaseNode_AddSkillBuff);
    if (node236 == nullptr) {
        node236 = new PhaseNode_AddSkillBuff(236, phase);
        node236->setConfigID(103147);
        node236->setConfigIDs({});
        node236->setTarget(0U);
        node236->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10314, 236, node236)
    }
    if (noInit == true) {
        return node236;
    }
    return node236;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 238) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 234, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10314, 238) {
    auto node238 = GET_SKILL_NODE(238, PhaseNode_RemoveSkillBuff);
    if (node238 == nullptr) {
        node238 = new PhaseNode_RemoveSkillBuff(238, phase);
        node238->setBuffID(0U);
        node238->setBuffIDs({});
        node238->setConfigID(103146);
        node238->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 238, node238)
    }
    if (noInit == true) {
        return node238;
    }
    return node238;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10314, 240) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_If::TRIGGER_FALSE, 242, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10314, 240) {
    auto node240 = GET_SKILL_NODE(240, PhaseNode_If);
    if (node240 == nullptr) {
        node240 = new PhaseNode_If(240, phase);
        CALL_REGISTER_SKILL_NODE(10314, 240, node240)
    }
    if (noInit == true) {
        return node240;
    }
    auto node220 = GET_SKILL_NODE(220, PhaseNode_FindSkillBuff);
    if (node220 != nullptr) node240->setCondition(node220->getResult());
    return node240;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 242) {
}

REGISTER_CREATE_SKILL_NODE(10314, 242) {
    auto node242 = GET_SKILL_NODE(242, PhaseNode_AddSkillBuff);
    if (node242 == nullptr) {
        node242 = new PhaseNode_AddSkillBuff(242, phase);
        node242->setConfigID(103146);
        node242->setConfigIDs({});
        node242->setTarget(0U);
        node242->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10314, 242, node242)
    }
    if (noInit == true) {
        return node242;
    }
    return node242;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 245) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 247, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10314, 245) {
    auto node245 = GET_SKILL_NODE(245, PhaseNode_RemoveSkillBuff);
    if (node245 == nullptr) {
        node245 = new PhaseNode_RemoveSkillBuff(245, phase);
        node245->setBuffID(0U);
        node245->setBuffIDs({});
        node245->setConfigID(103148);
        node245->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 245, node245)
    }
    if (noInit == true) {
        return node245;
    }
    return node245;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 247) {
    pnode->resizeTrigger(PhaseNode_RemoveSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RemoveSkillBuff>(PhaseNode_RemoveSkillBuff::TRIGGER_DONE, 249, PhaseNode_RemoveSkillBuff::FUNC_REMOVE, &PhaseNode_RemoveSkillBuff::Remove);
}

REGISTER_CREATE_SKILL_NODE(10314, 247) {
    auto node247 = GET_SKILL_NODE(247, PhaseNode_RemoveSkillBuff);
    if (node247 == nullptr) {
        node247 = new PhaseNode_RemoveSkillBuff(247, phase);
        node247->setBuffID(0U);
        node247->setBuffIDs({});
        node247->setConfigID(103147);
        node247->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 247, node247)
    }
    if (noInit == true) {
        return node247;
    }
    return node247;
}
//--------------------------------------------------------------------------------
// RemoveSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10314, 249) {
}

REGISTER_CREATE_SKILL_NODE(10314, 249) {
    auto node249 = GET_SKILL_NODE(249, PhaseNode_RemoveSkillBuff);
    if (node249 == nullptr) {
        node249 = new PhaseNode_RemoveSkillBuff(249, phase);
        node249->setBuffID(0U);
        node249->setBuffIDs({});
        node249->setConfigID(103146);
        node249->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10314, 249, node249)
    }
    if (noInit == true) {
        return node249;
    }
    return node249;
}

//--------------------------------------------------------------------------------
// SkillCreator_10314
//
class SkillCreator_10314 : public SkillCreator {
public:
    SkillCreator_10314() {}
    virtual ~SkillCreator_10314() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10314

//--------------------------------------------------------------------------------
// SkillPhase_10314
//
class SkillPhase_10314 : public SkillPhase {
public:
    SkillPhase_10314(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10314() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10314, 137) // TimeDown
        CASE_CREATE_SKILL_NODE(10314, 145) // CompareInt
        CASE_CREATE_SKILL_NODE(10314, 151) // StopEffect
        CASE_CREATE_SKILL_NODE(10314, 153) // StopEffect
        CASE_CREATE_SKILL_NODE(10314, 155) // StopEffect
        CASE_CREATE_SKILL_NODE(10314, 185) // If
        CASE_CREATE_SKILL_NODE(10314, 189) // SetBool
        CASE_CREATE_SKILL_NODE(10314, 191) // SetInt
        CASE_CREATE_SKILL_NODE(10314, 199) // Detect
        CASE_CREATE_SKILL_NODE(10314, 201) // Detect
        CASE_CREATE_SKILL_NODE(10314, 204) // If
        CASE_CREATE_SKILL_NODE(10314, 205) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 206) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 207) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 208) // If
        CASE_CREATE_SKILL_NODE(10314, 209) // If
        CASE_CREATE_SKILL_NODE(10314, 218) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 220) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 222) // FindSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 224) // If
        CASE_CREATE_SKILL_NODE(10314, 226) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 230) // If
        CASE_CREATE_SKILL_NODE(10314, 232) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 234) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 236) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 238) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 240) // If
        CASE_CREATE_SKILL_NODE(10314, 242) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 245) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 247) // RemoveSkillBuff
        CASE_CREATE_SKILL_NODE(10314, 249) // RemoveSkillBuff
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10314

SkillLogic* SkillCreator_10314::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10314_101341 = logic->getVariables().setVariable<int32_t>("101341");
    Variable_10314_101342 = logic->getVariables().setVariable<int32_t>("101342");
    Variable_10314_size = logic->getVariables().setVariable<bool>("size");
    //创建阶段phase
    auto phase = new SkillPhase_10314(1, logic, 1);
    //设置phase执行器
    phase->setDetectPhaseNode(1, 199);
    phase->setDetectPhaseNode(1, 201);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10314::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
