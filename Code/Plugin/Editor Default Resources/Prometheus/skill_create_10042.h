#pragma once

#include "node.hpp"
#include "skill.h"
#include "skill_factory.h"

#include "skill_psnode_actorfilternewpene.h"
#include "skill_psnode_addskillbuff.h"
#include "skill_psnode_addskillbuffs.h"
#include "skill_psnode_all.h"
#include "skill_psnode_areacollisionnewpene.h"
#include "skill_psnode_attachto.h"
#include "skill_psnode_cameraxyzshake.h"
#include "skill_psnode_createtriggernewpene.h"
#include "skill_psnode_delay.h"
#include "skill_psnode_destroycollider.h"
#include "skill_psnode_detect.h"
#include "skill_psnode_disable.h"
#include "skill_psnode_endphase.h"
#include "skill_psnode_getactorattribute.h"
#include "skill_psnode_getinputrotation.h"
#include "skill_psnode_getlocation.h"
#include "skill_psnode_getuint64svalue.h"
#include "skill_psnode_if.h"
#include "skill_psnode_isinterrupttype.h"
#include "skill_psnode_movenewpene.h"
#include "skill_psnode_playanimation.h"
#include "skill_psnode_playeffect.h"
#include "skill_psnode_playsound.h"
#include "skill_psnode_raiseevent.h"
#include "skill_psnode_resetcd.h"
#include "skill_psnode_setbool.h"
#include "skill_psnode_setuint64.h"
#include "skill_psnode_spawncollider.h"
#include "skill_psnode_startphase.h"
#include "skill_psnode_startpreinput.h"
#include "skill_psnode_stopeffect.h"
#include "skill_psnode_switchtoint.h"
#include "skill_psnode_triggercheck.h"
#include "skill_psnode_triggerupdate.h"

namespace pvp {

//变量声明
uint64_t Variable_10042_a100423 = 0;
uint64_t Variable_10042_a100424 = 0;
uint64_t Variable_10042_a100422 = 0;
uint64_t Variable_10042_InterruptAnimat = 0;
//--------------------------------------------------------------------------------
// TriggerUpdate
//
REGISTER_REGISTER_SKILL_NODE(10042, 753) {
}

REGISTER_CREATE_SKILL_NODE(10042, 753) {
    auto node753 = GET_SKILL_NODE(753, PhaseNode_TriggerUpdate);
    if (node753 == nullptr) {
        node753 = new PhaseNode_TriggerUpdate(753, phase);
        CALL_REGISTER_SKILL_NODE(10042, 753, node753)
    }
    if (noInit == true) {
        return node753;
    }
    return node753;
}
//--------------------------------------------------------------------------------
// StartPhase
//
REGISTER_REGISTER_SKILL_NODE(10042, 916) {
    pnode->resizeTrigger(PhaseNode_StartPhase::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_ResetCD>(PhaseNode_StartPhase::TRIGGER_START, 2159, PhaseNode_ResetCD::FUNC_DO, &PhaseNode_ResetCD::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 916) {
    auto node916 = GET_SKILL_NODE(916, PhaseNode_StartPhase);
    if (node916 == nullptr) {
        node916 = new PhaseNode_StartPhase(916, phase);
        CALL_REGISTER_SKILL_NODE(10042, 916, node916)
    }
    if (noInit == true) {
        return node916;
    }
    return node916;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10042, 1657) {
}

REGISTER_CREATE_SKILL_NODE(10042, 1657) {
    auto node1657 = GET_SKILL_NODE(1657, PhaseNode_PlaySound);
    if (node1657 == nullptr) {
        node1657 = new PhaseNode_PlaySound(1657, phase);
        node1657->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node1657->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node1657->setSoundID("SE_Hero101_Skill_B");
        node1657->setTarget(0U);
        node1657->setUsePos(false);
        node1657->setPosX(.00f);
        node1657->setPosY(.00f);
        node1657->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10042, 1657, node1657)
    }
    if (noInit == true) {
        return node1657;
    }
    return node1657;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10042, 1982) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_All>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 2158, PhaseNode_All::FUNC_CHECK1, &PhaseNode_All::Check1);
    pnode->regTrigger<PhaseNode_All>(PhaseNode_MoveNewPene::TRIGGER_DONE, 2158, PhaseNode_All::FUNC_CHECK1, &PhaseNode_All::Check1);
    pnode->regTrigger<PhaseNode_CreateTriggerNewPene>(PhaseNode_MoveNewPene::TRIGGER_STARTMOVE, 2150, PhaseNode_CreateTriggerNewPene::FUNC_CREATE, &PhaseNode_CreateTriggerNewPene::Create);
}

REGISTER_CREATE_SKILL_NODE(10042, 1982) {
    auto node1982 = GET_SKILL_NODE(1982, PhaseNode_MoveNewPene);
    if (node1982 == nullptr) {
        node1982 = new PhaseNode_MoveNewPene(1982, phase);
        node1982->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node1982->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node1982->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node1982->setPeneValue(5);
        node1982->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node1982->getVars().reserve(4);
        node1982->getVars().setVariable<float>(0, 18.00f);
        node1982->getVars().setVariable<float>(1, 12.00f);
        node1982->getVars().setVariable<float>(2, .00f);
        node1982->getVars().setVariable<float>(3, .00f);
        node1982->setreentry(false);
        node1982->setStopWhenFail(true);
        node1982->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10042, 1982, node1982)
    }
    if (noInit == true) {
        return node1982;
    }
    auto node2003 = GET_SKILL_NODE(2003, PhaseNode_SpawnCollider);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2003 != nullptr) node1982->setTarget(node2003->getColliderID());
    if (node2119 != nullptr) node1982->getVars().setVariable<float>(2, node2119->getAngle());
    return node1982;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 1999) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_Delay::TRIGGER_DONE, 2003, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 1999) {
    auto node1999 = GET_SKILL_NODE(1999, PhaseNode_Delay);
    if (node1999 == nullptr) {
        node1999 = new PhaseNode_Delay(1999, phase);
        node1999->setTime(.30f);
        CALL_REGISTER_SKILL_NODE(10042, 1999, node1999)
    }
    if (noInit == true) {
        return node1999;
    }
    return node1999;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2003) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_SpawnCollider::TRIGGER_DONE, 2057, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2003) {
    auto node2003 = GET_SKILL_NODE(2003, PhaseNode_SpawnCollider);
    if (node2003 == nullptr) {
        node2003 = new PhaseNode_SpawnCollider(2003, phase);
        node2003->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node2003->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2003->setMesh("");
        node2003->setMeshScale(.00f);
        node2003->setEffectID(100421);
        node2003->setEffectScale(1.00f);
        node2003->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node2003->setTypeParams(0, .50f);
        node2003->setTime(.80f);
        node2003->setPosZ(.00f);
        node2003->setreentry(false);
        node2003->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10042, 2003, node2003)
    }
    if (noInit == true) {
        return node2003;
    }
    auto node2117 = GET_SKILL_NODE(2117, PhaseNode_GetLocation);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2117 != nullptr) node2003->setPosX(node2117->getX());
    if (node2117 != nullptr) node2003->setPosY(node2117->getY());
    if (node2119 != nullptr) node2003->setRotation(node2119->getAngle());
    return node2003;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10042, 2005) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_AttachTo::TRIGGER_DONE, 2019, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2005) {
    auto node2005 = GET_SKILL_NODE(2005, PhaseNode_AttachTo);
    if (node2005 == nullptr) {
        node2005 = new PhaseNode_AttachTo(2005, phase);
        node2005->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2005->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2005->setChild(0U);
        node2005->setChangeRotation(false);
        node2005->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10042, 2005, node2005)
    }
    if (noInit == true) {
        return node2005;
    }
    auto node2003 = GET_SKILL_NODE(2003, PhaseNode_SpawnCollider);
    if (node2003 != nullptr) node2005->setParent(node2003->getColliderID());
    return node2005;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 2010) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 2012, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10042, 2010) {
    auto node2010 = GET_SKILL_NODE(2010, PhaseNode_Delay);
    if (node2010 == nullptr) {
        node2010 = new PhaseNode_Delay(2010, phase);
        node2010->setTime(.10f);
        CALL_REGISTER_SKILL_NODE(10042, 2010, node2010)
    }
    if (noInit == true) {
        return node2010;
    }
    return node2010;
}
//--------------------------------------------------------------------------------
// EndPhase
//
REGISTER_REGISTER_SKILL_NODE(10042, 2012) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2012) {
    auto node2012 = GET_SKILL_NODE(2012, PhaseNode_EndPhase);
    if (node2012 == nullptr) {
        node2012 = new PhaseNode_EndPhase(2012, phase);
        node2012->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2012->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10042, 2012, node2012)
    }
    if (noInit == true) {
        return node2012;
    }
    return node2012;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2016) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 2005, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2016) {
    auto node2016 = GET_SKILL_NODE(2016, PhaseNode_SpawnCollider);
    if (node2016 == nullptr) {
        node2016 = new PhaseNode_SpawnCollider(2016, phase);
        node2016->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node2016->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2016->setMesh("");
        node2016->setMeshScale(.00f);
        node2016->setEffectID(0);
        node2016->setEffectScale(.00f);
        node2016->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Rect);
        node2016->setTypeParams(0, 2.00f);
        node2016->setTypeParams(1, 3.00f);
        node2016->setTypeParams(2, .00f);
        node2016->setTypeParams(3, .00f);
        node2016->setTypeParams(4, .00f);
        node2016->setTime(.80f);
        node2016->setPosZ(.00f);
        node2016->setreentry(false);
        node2016->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10042, 2016, node2016)
    }
    if (noInit == true) {
        return node2016;
    }
    auto node2117 = GET_SKILL_NODE(2117, PhaseNode_GetLocation);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2117 != nullptr) node2016->setPosX(node2117->getX());
    if (node2117 != nullptr) node2016->setPosY(node2117->getY());
    if (node2119 != nullptr) node2016->setRotation(node2119->getAngle());
    return node2016;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10042, 2019) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 1982, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2019) {
    auto node2019 = GET_SKILL_NODE(2019, PhaseNode_AttachTo);
    if (node2019 == nullptr) {
        node2019 = new PhaseNode_AttachTo(2019, phase);
        node2019->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2019->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2019->setChangeRotation(false);
        node2019->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10042, 2019, node2019)
    }
    if (noInit == true) {
        return node2019;
    }
    auto node2003 = GET_SKILL_NODE(2003, PhaseNode_SpawnCollider);
    auto node2016 = GET_SKILL_NODE(2016, PhaseNode_SpawnCollider);
    if (node2003 != nullptr) node2019->setParent(node2003->getColliderID());
    if (node2016 != nullptr) node2019->setChild(node2016->getColliderID());
    return node2019;
}
//--------------------------------------------------------------------------------
// GetUInt64sValue
//
REGISTER_REGISTER_SKILL_NODE(10042, 2023) {
    pnode->resizeTrigger(PhaseNode_GetUInt64sValue::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetUInt64>(PhaseNode_GetUInt64sValue::TRIGGER_DONE, 2029, PhaseNode_SetUInt64::FUNC_SET, &PhaseNode_SetUInt64::Set);
}

REGISTER_CREATE_SKILL_NODE(10042, 2023) {
    auto node2023 = GET_SKILL_NODE(2023, PhaseNode_GetUInt64sValue);
    if (node2023 == nullptr) {
        node2023 = new PhaseNode_GetUInt64sValue(2023, phase);
        node2023->setIndex(0);
        CALL_REGISTER_SKILL_NODE(10042, 2023, node2023)
    }
    if (noInit == true) {
        return node2023;
    }
    auto node2152 = GET_SKILL_NODE(2152, PhaseNode_ActorFilterNewPene);
    if (node2152 != nullptr) node2023->setArr(node2152->getOutput());
    return node2023;
}
//--------------------------------------------------------------------------------
// SetUInt64
//
REGISTER_REGISTER_SKILL_NODE(10042, 2029) {
    pnode->resizeTrigger(PhaseNode_SetUInt64::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_SetUInt64::TRIGGER_DONE, 2049, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10042, 2029) {
    auto node2029 = GET_SKILL_NODE(2029, PhaseNode_SetUInt64);
    if (node2029 == nullptr) {
        node2029 = new PhaseNode_SetUInt64(2029, phase);
        node2029->setName("a100423");
        CALL_REGISTER_SKILL_NODE(10042, 2029, node2029)
    }
    if (noInit == true) {
        return node2029;
    }
    auto node2023 = GET_SKILL_NODE(2023, PhaseNode_GetUInt64sValue);
    if (node2023 != nullptr) node2029->setValue(node2023->getValue());
    return node2029;
}
//--------------------------------------------------------------------------------
// AddSkillBuff
//
REGISTER_REGISTER_SKILL_NODE(10042, 2031) {
    pnode->resizeTrigger(PhaseNode_AddSkillBuff::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_AddSkillBuff::TRIGGER_DONE, 2070, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2031) {
    auto node2031 = GET_SKILL_NODE(2031, PhaseNode_AddSkillBuff);
    if (node2031 == nullptr) {
        node2031 = new PhaseNode_AddSkillBuff(2031, phase);
        node2031->setConfigID(100421);
        node2031->setConfigIDs({});
        node2031->setAttribute({{}});
        CALL_REGISTER_SKILL_NODE(10042, 2031, node2031)
    }
    if (noInit == true) {
        return node2031;
    }
    auto node2023 = GET_SKILL_NODE(2023, PhaseNode_GetUInt64sValue);
    if (node2023 != nullptr) node2031->setTarget(node2023->getValue());
    return node2031;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2040) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AreaCollisionNewPene>(PhaseNode_GetLocation::TRIGGER_DONE, 2121, PhaseNode_AreaCollisionNewPene::FUNC_DO, &PhaseNode_AreaCollisionNewPene::Do);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_GetLocation::TRIGGER_DONE, 2097, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2040) {
    auto node2040 = GET_SKILL_NODE(2040, PhaseNode_GetLocation);
    if (node2040 == nullptr) {
        node2040 = new PhaseNode_GetLocation(2040, phase);
        node2040->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node2040->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10042, 2040, node2040)
    }
    if (noInit == true) {
        return node2040;
    }
    return node2040;
}
//--------------------------------------------------------------------------------
// AddSkillBuffs
//
REGISTER_REGISTER_SKILL_NODE(10042, 2042) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2042) {
    auto node2042 = GET_SKILL_NODE(2042, PhaseNode_AddSkillBuffs);
    if (node2042 == nullptr) {
        node2042 = new PhaseNode_AddSkillBuffs(2042, phase);
        node2042->setConfigID({100422,100423});
        CALL_REGISTER_SKILL_NODE(10042, 2042, node2042)
    }
    if (noInit == true) {
        return node2042;
    }
    auto node2121 = GET_SKILL_NODE(2121, PhaseNode_AreaCollisionNewPene);
    auto node2162 = GET_SKILL_NODE(2162, PhaseNode_GetActorAttribute);
    if (node2121 != nullptr) node2042->setTarget(node2121->getColliders());
    if (node2162 != nullptr) node2042->setAttribute(node2162->getAttribute());
    return node2042;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10042, 2049) {
    pnode->resizeTrigger(PhaseNode_SetBool::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuff>(PhaseNode_SetBool::TRIGGER_DONE, 2031, PhaseNode_AddSkillBuff::FUNC_ADD, &PhaseNode_AddSkillBuff::Add);
}

REGISTER_CREATE_SKILL_NODE(10042, 2049) {
    auto node2049 = GET_SKILL_NODE(2049, PhaseNode_SetBool);
    if (node2049 == nullptr) {
        node2049 = new PhaseNode_SetBool(2049, phase);
        node2049->setName("a100424");
        node2049->setValue(true);
        CALL_REGISTER_SKILL_NODE(10042, 2049, node2049)
    }
    if (noInit == true) {
        return node2049;
    }
    return node2049;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10042, 2051) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_If::TRIGGER_FALSE, 2055, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_FALSE, 2059, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_If::TRIGGER_TRUE, 2072, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_If::TRIGGER_TRUE, 2040, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_If::TRIGGER_TRUE, 2074, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 2061, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2051) {
    auto node2051 = GET_SKILL_NODE(2051, PhaseNode_If);
    if (node2051 == nullptr) {
        node2051 = new PhaseNode_If(2051, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2051, node2051)
    }
    if (noInit == true) {
        return node2051;
    }
    auto variables = node2051->getVariables();
    if (variables != nullptr) {
        node2051->setCondition(variables->getVariable<bool>(Variable_10042_a100424));
    }
    return node2051;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2055) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2055) {
    auto node2055 = GET_SKILL_NODE(2055, PhaseNode_DestroyCollider);
    if (node2055 == nullptr) {
        node2055 = new PhaseNode_DestroyCollider(2055, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2055, node2055)
    }
    if (noInit == true) {
        return node2055;
    }
    auto node2003 = GET_SKILL_NODE(2003, PhaseNode_SpawnCollider);
    if (node2003 != nullptr) node2055->setColliderID(node2003->getColliderID());
    return node2055;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2057) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2110, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2057) {
    auto node2057 = GET_SKILL_NODE(2057, PhaseNode_PlayAnimation);
    if (node2057 == nullptr) {
        node2057 = new PhaseNode_PlayAnimation(2057, phase);
        node2057->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2057->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2057->setTarget(0U);
        node2057->setAnimation("Skill2S2");
        node2057->setParameter("");
        node2057->setValue(false);
        CALL_REGISTER_SKILL_NODE(10042, 2057, node2057)
    }
    if (noInit == true) {
        return node2057;
    }
    return node2057;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2059) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2129, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2104, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2059) {
    auto node2059 = GET_SKILL_NODE(2059, PhaseNode_PlayAnimation);
    if (node2059 == nullptr) {
        node2059 = new PhaseNode_PlayAnimation(2059, phase);
        node2059->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2059->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2059->setTarget(0U);
        node2059->setAnimation("Skill2S4");
        node2059->setParameter("");
        node2059->setValue(false);
        CALL_REGISTER_SKILL_NODE(10042, 2059, node2059)
    }
    if (noInit == true) {
        return node2059;
    }
    return node2059;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2061) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2127, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_StopEffect>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2104, PhaseNode_StopEffect::FUNC_DO, &PhaseNode_StopEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2061) {
    auto node2061 = GET_SKILL_NODE(2061, PhaseNode_PlayAnimation);
    if (node2061 == nullptr) {
        node2061 = new PhaseNode_PlayAnimation(2061, phase);
        node2061->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2061->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2061->setTarget(0U);
        node2061->setAnimation("Skill2S3");
        node2061->setParameter("");
        node2061->setValue(false);
        CALL_REGISTER_SKILL_NODE(10042, 2061, node2061)
    }
    if (noInit == true) {
        return node2061;
    }
    return node2061;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 2063) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_EndPhase>(PhaseNode_Delay::TRIGGER_DONE, 2012, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10042, 2063) {
    auto node2063 = GET_SKILL_NODE(2063, PhaseNode_Delay);
    if (node2063 == nullptr) {
        node2063 = new PhaseNode_Delay(2063, phase);
        node2063->setTime(.05f);
        CALL_REGISTER_SKILL_NODE(10042, 2063, node2063)
    }
    if (noInit == true) {
        return node2063;
    }
    return node2063;
}
//--------------------------------------------------------------------------------
// SpawnCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2065) {
    pnode->resizeTrigger(PhaseNode_SpawnCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_All>(PhaseNode_SpawnCollider::TRIGGER_DONE, 2158, PhaseNode_All::FUNC_CHECK2, &PhaseNode_All::Check2);
    pnode->regTrigger<PhaseNode_AttachTo>(PhaseNode_SpawnCollider::TRIGGER_DONE, 2068, PhaseNode_AttachTo::FUNC_DO, &PhaseNode_AttachTo::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2065) {
    auto node2065 = GET_SKILL_NODE(2065, PhaseNode_SpawnCollider);
    if (node2065 == nullptr) {
        node2065 = new PhaseNode_SpawnCollider(2065, phase);
        node2065->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node2065->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2065->setMesh("");
        node2065->setMeshScale(.00f);
        node2065->setEffectID(0);
        node2065->setEffectScale(.00f);
        node2065->setType(PhaseNode_SpawnCollider::SpawnCollider_Type::Circle);
        node2065->setTypeParams(0, .50f);
        node2065->setTime(.80f);
        node2065->setPosZ(.00f);
        node2065->setreentry(false);
        node2065->setCheckPeneSound(false);
        CALL_REGISTER_SKILL_NODE(10042, 2065, node2065)
    }
    if (noInit == true) {
        return node2065;
    }
    auto node2070 = GET_SKILL_NODE(2070, PhaseNode_GetLocation);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2070 != nullptr) node2065->setPosX(node2070->getX());
    if (node2070 != nullptr) node2065->setPosY(node2070->getY());
    if (node2119 != nullptr) node2065->setRotation(node2119->getAngle());
    return node2065;
}
//--------------------------------------------------------------------------------
// AttachTo
//
REGISTER_REGISTER_SKILL_NODE(10042, 2068) {
    pnode->resizeTrigger(PhaseNode_AttachTo::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_AttachTo::TRIGGER_DONE, 2074, PhaseNode_MoveNewPene::FUNC_DO, &PhaseNode_MoveNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2068) {
    auto node2068 = GET_SKILL_NODE(2068, PhaseNode_AttachTo);
    if (node2068 == nullptr) {
        node2068 = new PhaseNode_AttachTo(2068, phase);
        node2068->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2068->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2068->setChangeRotation(false);
        node2068->setreentry(false);
        CALL_REGISTER_SKILL_NODE(10042, 2068, node2068)
    }
    if (noInit == true) {
        return node2068;
    }
    auto node2065 = GET_SKILL_NODE(2065, PhaseNode_SpawnCollider);
    auto node2023 = GET_SKILL_NODE(2023, PhaseNode_GetUInt64sValue);
    if (node2065 != nullptr) node2068->setParent(node2065->getColliderID());
    if (node2023 != nullptr) node2068->setChild(node2023->getValue());
    return node2068;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2070) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_GetLocation::TRIGGER_DONE, 2065, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2070) {
    auto node2070 = GET_SKILL_NODE(2070, PhaseNode_GetLocation);
    if (node2070 == nullptr) {
        node2070 = new PhaseNode_GetLocation(2070, phase);
        node2070->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10042, 2070, node2070)
    }
    if (noInit == true) {
        return node2070;
    }
    auto node2023 = GET_SKILL_NODE(2023, PhaseNode_GetUInt64sValue);
    if (node2023 != nullptr) node2070->setTarget(node2023->getValue());
    return node2070;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2072) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_DestroyCollider::TRIGGER_DONE, 2085, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2072) {
    auto node2072 = GET_SKILL_NODE(2072, PhaseNode_DestroyCollider);
    if (node2072 == nullptr) {
        node2072 = new PhaseNode_DestroyCollider(2072, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2072, node2072)
    }
    if (noInit == true) {
        return node2072;
    }
    auto node2065 = GET_SKILL_NODE(2065, PhaseNode_SpawnCollider);
    if (node2065 != nullptr) node2072->setColliderID(node2065->getColliderID());
    return node2072;
}
//--------------------------------------------------------------------------------
// MoveNewPene
//
REGISTER_REGISTER_SKILL_NODE(10042, 2074) {
    pnode->resizeTrigger(PhaseNode_MoveNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_MoveNewPene::TRIGGER_BLOCKBYWALL, 1982, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
    pnode->regTrigger<PhaseNode_MoveNewPene>(PhaseNode_MoveNewPene::TRIGGER_DONE, 1982, PhaseNode_MoveNewPene::FUNC_STOP, &PhaseNode_MoveNewPene::Stop);
}

REGISTER_CREATE_SKILL_NODE(10042, 2074) {
    auto node2074 = GET_SKILL_NODE(2074, PhaseNode_MoveNewPene);
    if (node2074 == nullptr) {
        node2074 = new PhaseNode_MoveNewPene(2074, phase);
        node2074->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);
        node2074->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2074->setPeneType(PhaseNode_MoveNewPene::MoveNewPene_PeneType::Move);
        node2074->setPeneValue(5);
        node2074->setType(PhaseNode_MoveNewPene::MoveNewPene_Type::Charge);
        node2074->getVars().reserve(4);
        node2074->getVars().setVariable<float>(0, 18.00f);
        node2074->getVars().setVariable<float>(1, 12.00f);
        node2074->getVars().setVariable<float>(2, .00f);
        node2074->getVars().setVariable<float>(3, .00f);
        node2074->setreentry(false);
        node2074->setStopWhenFail(true);
        node2074->setCheckFaction(PhaseNode_MoveNewPene::MoveNewPene_CheckFaction::Enemy);
        CALL_REGISTER_SKILL_NODE(10042, 2074, node2074)
    }
    if (noInit == true) {
        return node2074;
    }
    auto node2065 = GET_SKILL_NODE(2065, PhaseNode_SpawnCollider);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2065 != nullptr) node2074->setTarget(node2065->getColliderID());
    if (node2119 != nullptr) node2074->getVars().setVariable<float>(2, node2119->getAngle());
    return node2074;
}
//--------------------------------------------------------------------------------
// DestroyCollider
//
REGISTER_REGISTER_SKILL_NODE(10042, 2085) {
    pnode->resizeTrigger(PhaseNode_DestroyCollider::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_DestroyCollider>(PhaseNode_DestroyCollider::TRIGGER_DONE, 2055, PhaseNode_DestroyCollider::FUNC_DO, &PhaseNode_DestroyCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2085) {
    auto node2085 = GET_SKILL_NODE(2085, PhaseNode_DestroyCollider);
    if (node2085 == nullptr) {
        node2085 = new PhaseNode_DestroyCollider(2085, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2085, node2085)
    }
    if (noInit == true) {
        return node2085;
    }
    auto node2016 = GET_SKILL_NODE(2016, PhaseNode_SpawnCollider);
    if (node2016 != nullptr) node2085->setColliderID(node2016->getColliderID());
    return node2085;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10042, 2097) {
    pnode->resizeTrigger(PhaseNode_PlayEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlayEffect::TRIGGER_DONE, 2100, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2097) {
    auto node2097 = GET_SKILL_NODE(2097, PhaseNode_PlayEffect);
    if (node2097 == nullptr) {
        node2097 = new PhaseNode_PlayEffect(2097, phase);
        node2097->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2097->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2097->setEffectID(100423);
        node2097->setChangeColor(false);
        node2097->setType(PhaseNode_PlayEffect::PlayEffect_Type::ToPos);
        node2097->getVars().reserve(3);
        node2097->getVars().setVariable<float>(0, .00f);
        node2097->getVars().setVariable<float>(1, .00f);
        node2097->getVars().setVariable<float>(2, .00f);
        node2097->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2097, node2097)
    }
    if (noInit == true) {
        return node2097;
    }
    auto node2040 = GET_SKILL_NODE(2040, PhaseNode_GetLocation);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2040 != nullptr) node2097->getVars().setVariable<float>(0, node2040->getX());
    if (node2040 != nullptr) node2097->getVars().setVariable<float>(1, node2040->getY());
    if (node2119 != nullptr) node2097->setRotation(node2119->getAngle());
    return node2097;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10042, 2100) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_CameraXYZShake>(PhaseNode_PlaySound::TRIGGER_DONE, 2114, PhaseNode_CameraXYZShake::FUNC_DO, &PhaseNode_CameraXYZShake::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2100) {
    auto node2100 = GET_SKILL_NODE(2100, PhaseNode_PlaySound);
    if (node2100 == nullptr) {
        node2100 = new PhaseNode_PlaySound(2100, phase);
        node2100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2100->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2100->setSoundID("SE_Hero101_Skill_B_P2");
        node2100->setTarget(0U);
        node2100->setUsePos(true);
        node2100->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2100, node2100)
    }
    if (noInit == true) {
        return node2100;
    }
    auto node2040 = GET_SKILL_NODE(2040, PhaseNode_GetLocation);
    if (node2040 != nullptr) node2100->setPosX(node2040->getX());
    if (node2040 != nullptr) node2100->setPosY(node2040->getY());
    return node2100;
}
//--------------------------------------------------------------------------------
// Disable
//
REGISTER_REGISTER_SKILL_NODE(10042, 2102) {
    pnode->resizeTrigger(PhaseNode_Disable::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_Disable::TRIGGER_DONE, 2167, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2102) {
    auto node2102 = GET_SKILL_NODE(2102, PhaseNode_Disable);
    if (node2102 == nullptr) {
        node2102 = new PhaseNode_Disable(2102, phase);
        node2102->setTarget(0U);
        node2102->setMove(true);
        node2102->setSkill(true);
        node2102->setShoot(true);
        node2102->setTime(2.00f);
        node2102->setRotate(true);
        CALL_REGISTER_SKILL_NODE(10042, 2102, node2102)
    }
    if (noInit == true) {
        return node2102;
    }
    return node2102;
}
//--------------------------------------------------------------------------------
// StopEffect
//
REGISTER_REGISTER_SKILL_NODE(10042, 2104) {
    pnode->resizeTrigger(PhaseNode_StopEffect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayEffect>(PhaseNode_StopEffect::TRIGGER_DONE, 2106, PhaseNode_PlayEffect::FUNC_DO, &PhaseNode_PlayEffect::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2104) {
    auto node2104 = GET_SKILL_NODE(2104, PhaseNode_StopEffect);
    if (node2104 == nullptr) {
        node2104 = new PhaseNode_StopEffect(2104, phase);
        node2104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2104->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2104->setEffectID(100421);
        CALL_REGISTER_SKILL_NODE(10042, 2104, node2104)
    }
    if (noInit == true) {
        return node2104;
    }
    return node2104;
}
//--------------------------------------------------------------------------------
// PlayEffect
//
REGISTER_REGISTER_SKILL_NODE(10042, 2106) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2106) {
    auto node2106 = GET_SKILL_NODE(2106, PhaseNode_PlayEffect);
    if (node2106 == nullptr) {
        node2106 = new PhaseNode_PlayEffect(2106, phase);
        node2106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2106->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2106->setEffectID(100422);
        node2106->setChangeColor(false);
        node2106->setType(PhaseNode_PlayEffect::PlayEffect_Type::WithTarget);
        node2106->getVars().reserve(5);
        node2106->getVars().setVariable<uint64_t>(0, 0U);
        node2106->getVars().setVariable<std::string>(1, "");
        node2106->getVars().setVariable<float>(2, .00f);
        node2106->getVars().setVariable<float>(3, .00f);
        node2106->getVars().setVariable<float>(4, .00f);
        node2106->setScale(1.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2106, node2106)
    }
    if (noInit == true) {
        return node2106;
    }
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2119 != nullptr) node2106->setRotation(node2119->getAngle());
    return node2106;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10042, 2110) {
    pnode->resizeTrigger(PhaseNode_CameraXYZShake::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SpawnCollider>(PhaseNode_CameraXYZShake::TRIGGER_DONE, 2016, PhaseNode_SpawnCollider::FUNC_DO, &PhaseNode_SpawnCollider::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2110) {
    auto node2110 = GET_SKILL_NODE(2110, PhaseNode_CameraXYZShake);
    if (node2110 == nullptr) {
        node2110 = new PhaseNode_CameraXYZShake(2110, phase);
        node2110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2110->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2110->setShakeStyle(1);
        node2110->setTarget(0U);
        node2110->setX(.10f);
        node2110->setY(.10f);
        node2110->setZ(.10f);
        node2110->setDuration(.10f);
        node2110->setTimes(2);
        CALL_REGISTER_SKILL_NODE(10042, 2110, node2110)
    }
    if (noInit == true) {
        return node2110;
    }
    return node2110;
}
//--------------------------------------------------------------------------------
// CameraXYZShake
//
REGISTER_REGISTER_SKILL_NODE(10042, 2114) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2114) {
    auto node2114 = GET_SKILL_NODE(2114, PhaseNode_CameraXYZShake);
    if (node2114 == nullptr) {
        node2114 = new PhaseNode_CameraXYZShake(2114, phase);
        node2114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2114->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2114->setShakeStyle(1);
        node2114->setTarget(0U);
        node2114->setX(.30f);
        node2114->setY(.20f);
        node2114->setZ(.10f);
        node2114->setDuration(.20f);
        node2114->setTimes(5);
        CALL_REGISTER_SKILL_NODE(10042, 2114, node2114)
    }
    if (noInit == true) {
        return node2114;
    }
    return node2114;
}
//--------------------------------------------------------------------------------
// GetLocation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2117) {
    pnode->resizeTrigger(PhaseNode_GetLocation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetInputRotation>(PhaseNode_GetLocation::TRIGGER_DONE, 2119, PhaseNode_GetInputRotation::FUNC_DO, &PhaseNode_GetInputRotation::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2117) {
    auto node2117 = GET_SKILL_NODE(2117, PhaseNode_GetLocation);
    if (node2117 == nullptr) {
        node2117 = new PhaseNode_GetLocation(2117, phase);
        node2117->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        node2117->setTarget(0U);
        CALL_REGISTER_SKILL_NODE(10042, 2117, node2117)
    }
    if (noInit == true) {
        return node2117;
    }
    return node2117;
}
//--------------------------------------------------------------------------------
// GetInputRotation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2119) {
    pnode->resizeTrigger(PhaseNode_GetInputRotation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_GetInputRotation::TRIGGER_DONE, 2102, PhaseNode_Disable::FUNC_DO, &PhaseNode_Disable::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2119) {
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2119 == nullptr) {
        node2119 = new PhaseNode_GetInputRotation(2119, phase);
        node2119->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncInfoClient, true);
        CALL_REGISTER_SKILL_NODE(10042, 2119, node2119)
    }
    if (noInit == true) {
        return node2119;
    }
    return node2119;
}
//--------------------------------------------------------------------------------
// AreaCollisionNewPene
//
REGISTER_REGISTER_SKILL_NODE(10042, 2121) {
    pnode->resizeTrigger(PhaseNode_AreaCollisionNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_AddSkillBuffs>(PhaseNode_AreaCollisionNewPene::TRIGGER_DONE, 2042, PhaseNode_AddSkillBuffs::FUNC_ADD, &PhaseNode_AddSkillBuffs::Add);
}

REGISTER_CREATE_SKILL_NODE(10042, 2121) {
    auto node2121 = GET_SKILL_NODE(2121, PhaseNode_AreaCollisionNewPene);
    if (node2121 == nullptr) {
        node2121 = new PhaseNode_AreaCollisionNewPene(2121, phase);
        node2121->setState(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_State::Alive);
        node2121->setFaction(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Faction::Enemy);
        node2121->setOnHero(true);
        node2121->setOnMinion(true);
        node2121->setOnDestruct(true);
        node2121->setOnShield(false);
        node2121->setType(PhaseNode_AreaCollisionNewPene::AreaCollisionNewPene_Type::Rect);
        node2121->setTypeParams(0, 3.00f);
        node2121->setTypeParams(1, 3.00f);
        node2121->setPositionZ(.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2121, node2121)
    }
    if (noInit == true) {
        return node2121;
    }
    auto node2040 = GET_SKILL_NODE(2040, PhaseNode_GetLocation);
    auto node2119 = GET_SKILL_NODE(2119, PhaseNode_GetInputRotation);
    if (node2040 != nullptr) node2121->setPositionX(node2040->getX());
    if (node2040 != nullptr) node2121->setPositionY(node2040->getY());
    if (node2119 != nullptr) node2121->setRotation(node2119->getAngle());
    return node2121;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 2127) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 2063, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_Delay::TRIGGER_DONE, 2102, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10042, 2127) {
    auto node2127 = GET_SKILL_NODE(2127, PhaseNode_Delay);
    if (node2127 == nullptr) {
        node2127 = new PhaseNode_Delay(2127, phase);
        node2127->setTime(.71f);
        CALL_REGISTER_SKILL_NODE(10042, 2127, node2127)
    }
    if (noInit == true) {
        return node2127;
    }
    return node2127;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 2129) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_Delay::TRIGGER_DONE, 2010, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Disable>(PhaseNode_Delay::TRIGGER_DONE, 2102, PhaseNode_Disable::FUNC_CANCLE, &PhaseNode_Disable::Cancle);
}

REGISTER_CREATE_SKILL_NODE(10042, 2129) {
    auto node2129 = GET_SKILL_NODE(2129, PhaseNode_Delay);
    if (node2129 == nullptr) {
        node2129 = new PhaseNode_Delay(2129, phase);
        node2129->setTime(.70f);
        CALL_REGISTER_SKILL_NODE(10042, 2129, node2129)
    }
    if (noInit == true) {
        return node2129;
    }
    return node2129;
}
//--------------------------------------------------------------------------------
// CreateTriggerNewPene
//
REGISTER_REGISTER_SKILL_NODE(10042, 2150) {
    pnode->resizeTrigger(PhaseNode_CreateTriggerNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_TriggerCheck>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONCREATED, 2155, PhaseNode_TriggerCheck::FUNC_START, &PhaseNode_TriggerCheck::Start);
    pnode->regTrigger<PhaseNode_All>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONDETECTNONE, 2158, PhaseNode_All::FUNC_CHECK2, &PhaseNode_All::Check2);
    pnode->regTrigger<PhaseNode_ActorFilterNewPene>(PhaseNode_CreateTriggerNewPene::TRIGGER_ONTRIGGED, 2152, PhaseNode_ActorFilterNewPene::FUNC_DO, &PhaseNode_ActorFilterNewPene::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2150) {
    auto node2150 = GET_SKILL_NODE(2150, PhaseNode_CreateTriggerNewPene);
    if (node2150 == nullptr) {
        node2150 = new PhaseNode_CreateTriggerNewPene(2150, phase);
        node2150->setType(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_Type::In);
        node2150->setState(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_State::Alive);
        node2150->setCheckFaction(PhaseNode_CreateTriggerNewPene::CreateTriggerNewPene_CheckFaction::Enemy);
        node2150->setOnHero(true);
        node2150->setOnMinion(true);
        node2150->setOnDestruct(true);
        node2150->setOnShield(false);
        CALL_REGISTER_SKILL_NODE(10042, 2150, node2150)
    }
    if (noInit == true) {
        return node2150;
    }
    auto node2016 = GET_SKILL_NODE(2016, PhaseNode_SpawnCollider);
    if (node2016 != nullptr) node2150->setColliderID(node2016->getColliderID());
    return node2150;
}
//--------------------------------------------------------------------------------
// ActorFilterNewPene
//
REGISTER_REGISTER_SKILL_NODE(10042, 2152) {
    pnode->resizeTrigger(PhaseNode_ActorFilterNewPene::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetUInt64sValue>(PhaseNode_ActorFilterNewPene::TRIGGER_DONE, 2023, PhaseNode_GetUInt64sValue::FUNC_DO, &PhaseNode_GetUInt64sValue::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2152) {
    auto node2152 = GET_SKILL_NODE(2152, PhaseNode_ActorFilterNewPene);
    if (node2152 == nullptr) {
        node2152 = new PhaseNode_ActorFilterNewPene(2152, phase);
        node2152->setHero(true);
        node2152->setMinion(true);
        node2152->setDestruct(true);
        node2152->setShield(false);
        node2152->setTotalCount(1);
        node2152->setPerCount(0);
        CALL_REGISTER_SKILL_NODE(10042, 2152, node2152)
    }
    if (noInit == true) {
        return node2152;
    }
    auto node2150 = GET_SKILL_NODE(2150, PhaseNode_CreateTriggerNewPene);
    if (node2150 != nullptr) node2152->setInput(node2150->getOther());
    return node2152;
}
//--------------------------------------------------------------------------------
// TriggerCheck
//
REGISTER_REGISTER_SKILL_NODE(10042, 2155) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2155) {
    auto node2155 = GET_SKILL_NODE(2155, PhaseNode_TriggerCheck);
    if (node2155 == nullptr) {
        node2155 = new PhaseNode_TriggerCheck(2155, phase);
        auto node753 = GET_SKILL_NODE(753, PhaseNode_TriggerUpdate);
        if (node753 != nullptr) node753->addTriggerCheck(node2155);
        
        CALL_REGISTER_SKILL_NODE(10042, 2155, node2155)
    }
    if (noInit == true) {
        return node2155;
    }
    auto node2150 = GET_SKILL_NODE(2150, PhaseNode_CreateTriggerNewPene);
    if (node2150 != nullptr) node2155->setTrigger(0, node2150->getTriggerID());
    return node2155;
}
//--------------------------------------------------------------------------------
// All
//
REGISTER_REGISTER_SKILL_NODE(10042, 2158) {
    pnode->resizeTrigger(PhaseNode_All::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_All::TRIGGER_DONE, 2051, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10042, 2158) {
    auto node2158 = GET_SKILL_NODE(2158, PhaseNode_All);
    if (node2158 == nullptr) {
        node2158 = new PhaseNode_All(2158, phase);
        node2158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2158->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10042, 2158, node2158)
    }
    if (noInit == true) {
        return node2158;
    }
    return node2158;
}
//--------------------------------------------------------------------------------
// ResetCD
//
REGISTER_REGISTER_SKILL_NODE(10042, 2159) {
    pnode->resizeTrigger(PhaseNode_ResetCD::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_ResetCD::TRIGGER_DONE, 2160, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2159) {
    auto node2159 = GET_SKILL_NODE(2159, PhaseNode_ResetCD);
    if (node2159 == nullptr) {
        node2159 = new PhaseNode_ResetCD(2159, phase);
        node2159->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2159->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2159->setLockSkill(false);
        CALL_REGISTER_SKILL_NODE(10042, 2159, node2159)
    }
    if (noInit == true) {
        return node2159;
    }
    return node2159;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2160) {
    pnode->resizeTrigger(PhaseNode_PlayAnimation::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetActorAttribute>(PhaseNode_PlayAnimation::TRIGGER_DONE, 2162, PhaseNode_GetActorAttribute::FUNC_GET, &PhaseNode_GetActorAttribute::Get);
}

REGISTER_CREATE_SKILL_NODE(10042, 2160) {
    auto node2160 = GET_SKILL_NODE(2160, PhaseNode_PlayAnimation);
    if (node2160 == nullptr) {
        node2160 = new PhaseNode_PlayAnimation(2160, phase);
        node2160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2160->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2160->setTarget(0U);
        node2160->setAnimation("Skill2S1");
        node2160->setParameter("");
        node2160->setValue(false);
        CALL_REGISTER_SKILL_NODE(10042, 2160, node2160)
    }
    if (noInit == true) {
        return node2160;
    }
    return node2160;
}
//--------------------------------------------------------------------------------
// PlaySound
//
REGISTER_REGISTER_SKILL_NODE(10042, 2161) {
    pnode->resizeTrigger(PhaseNode_PlaySound::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_GetLocation>(PhaseNode_PlaySound::TRIGGER_DONE, 2117, PhaseNode_GetLocation::FUNC_DO, &PhaseNode_GetLocation::Do);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_PlaySound::TRIGGER_DONE, 1657, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2161) {
    auto node2161 = GET_SKILL_NODE(2161, PhaseNode_PlaySound);
    if (node2161 == nullptr) {
        node2161 = new PhaseNode_PlaySound(2161, phase);
        node2161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2161->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2161->setSoundID("VO_Hero101_Skill_B");
        node2161->setTarget(0U);
        node2161->setUsePos(false);
        node2161->setPosX(.00f);
        node2161->setPosY(.00f);
        node2161->setPosZ(.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2161, node2161)
    }
    if (noInit == true) {
        return node2161;
    }
    return node2161;
}
//--------------------------------------------------------------------------------
// GetActorAttribute
//
REGISTER_REGISTER_SKILL_NODE(10042, 2162) {
    pnode->resizeTrigger(PhaseNode_GetActorAttribute::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlaySound>(PhaseNode_GetActorAttribute::TRIGGER_DONE, 2161, PhaseNode_PlaySound::FUNC_PLAY, &PhaseNode_PlaySound::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2162) {
    auto node2162 = GET_SKILL_NODE(2162, PhaseNode_GetActorAttribute);
    if (node2162 == nullptr) {
        node2162 = new PhaseNode_GetActorAttribute(2162, phase);
        node2162->setTarget(0U);
        node2162->setType({});
        CALL_REGISTER_SKILL_NODE(10042, 2162, node2162)
    }
    if (noInit == true) {
        return node2162;
    }
    return node2162;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10042, 2164) {
    pnode->resizeTrigger(PhaseNode_Detect::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_IsInterruptType>(PhaseNode_Detect::TRIGGER_ON, 2170, PhaseNode_IsInterruptType::FUNC_DO, &PhaseNode_IsInterruptType::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2164) {
    auto node2164 = GET_SKILL_NODE(2164, PhaseNode_Detect);
    if (node2164 == nullptr) {
        node2164 = new PhaseNode_Detect(2164, phase);
        node2164->setSelf(0U);
        node2164->setEvent("daduan_001");
        node2164->setType(PhaseNode_Detect::Detect_Type::Interrupt_Skill);
        node2164->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10042, 2164, node2164)
    }
    if (noInit == true) {
        return node2164;
    }
    return node2164;
}
//--------------------------------------------------------------------------------
// SwitchToInt
//
REGISTER_REGISTER_SKILL_NODE(10042, 2165) {
    pnode->resizeTrigger(4);
    pnode->regTrigger<PhaseNode_EndPhase>(1, 2012, PhaseNode_EndPhase::FUNC_STOP, &PhaseNode_EndPhase::Stop);
}

REGISTER_CREATE_SKILL_NODE(10042, 2165) {
    auto node2165 = GET_SKILL_NODE(2165, PhaseNode_SwitchToInt);
    if (node2165 == nullptr) {
        node2165 = new PhaseNode_SwitchToInt(2165, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2165, node2165)
    }
    if (noInit == true) {
        return node2165;
    }
    auto variables = node2165->getVariables();
    if (variables != nullptr) {
        node2165->setSelection(variables->getVariable<int32_t>(Variable_10042_a100422));
    }
    return node2165;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10042, 2167) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_RaiseEvent>(PhaseNode_RaiseEvent::TRIGGER_DONE, 2176, PhaseNode_RaiseEvent::FUNC_DO, &PhaseNode_RaiseEvent::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2167) {
    auto node2167 = GET_SKILL_NODE(2167, PhaseNode_RaiseEvent);
    if (node2167 == nullptr) {
        node2167 = new PhaseNode_RaiseEvent(2167, phase);
        node2167->setEvent("daduan_001");
        node2167->setTarget(0U);
        node2167->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node2167->setTypeParams(0, 0);
        node2167->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10042, 2167, node2167)
    }
    if (noInit == true) {
        return node2167;
    }
    return node2167;
}
//--------------------------------------------------------------------------------
// StartPreInput
//
REGISTER_REGISTER_SKILL_NODE(10042, 2168) {
    pnode->resizeTrigger(PhaseNode_StartPreInput::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 1999, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
    pnode->regTrigger<PhaseNode_Delay>(PhaseNode_StartPreInput::TRIGGER_DONE, 2172, PhaseNode_Delay::FUNC_DELAY, &PhaseNode_Delay::Delay);
}

REGISTER_CREATE_SKILL_NODE(10042, 2168) {
    auto node2168 = GET_SKILL_NODE(2168, PhaseNode_StartPreInput);
    if (node2168 == nullptr) {
        node2168 = new PhaseNode_StartPreInput(2168, phase);
        node2168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2168->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2168->setDelayTime(.00f);
        CALL_REGISTER_SKILL_NODE(10042, 2168, node2168)
    }
    if (noInit == true) {
        return node2168;
    }
    return node2168;
}
//--------------------------------------------------------------------------------
// If
//
REGISTER_REGISTER_SKILL_NODE(10042, 2169) {
    pnode->resizeTrigger(PhaseNode_If::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_PlayAnimation>(PhaseNode_If::TRIGGER_TRUE, 2171, PhaseNode_PlayAnimation::FUNC_PLAY, &PhaseNode_PlayAnimation::Play);
}

REGISTER_CREATE_SKILL_NODE(10042, 2169) {
    auto node2169 = GET_SKILL_NODE(2169, PhaseNode_If);
    if (node2169 == nullptr) {
        node2169 = new PhaseNode_If(2169, phase);
        CALL_REGISTER_SKILL_NODE(10042, 2169, node2169)
    }
    if (noInit == true) {
        return node2169;
    }
    auto variables = node2169->getVariables();
    if (variables != nullptr) {
        node2169->setCondition(variables->getVariable<bool>(Variable_10042_InterruptAnimat));
    }
    return node2169;
}
//--------------------------------------------------------------------------------
// IsInterruptType
//
REGISTER_REGISTER_SKILL_NODE(10042, 2170) {
    pnode->resizeTrigger(PhaseNode_IsInterruptType::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SwitchToInt>(PhaseNode_IsInterruptType::TRIGGER_BUFF, 2165, PhaseNode_SwitchToInt::FUNC_SWITCH, &PhaseNode_SwitchToInt::Switch);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_POSCHANGE, 2169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTAIM, 2169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTFIRE, 2169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_STARTRELOAD, 2169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
    pnode->regTrigger<PhaseNode_If>(PhaseNode_IsInterruptType::TRIGGER_USESKILL, 2169, PhaseNode_If::FUNC_IF, &PhaseNode_If::If);
}

REGISTER_CREATE_SKILL_NODE(10042, 2170) {
    auto node2170 = GET_SKILL_NODE(2170, PhaseNode_IsInterruptType);
    if (node2170 == nullptr) {
        node2170 = new PhaseNode_IsInterruptType(2170, phase);
        node2170->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2170->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        CALL_REGISTER_SKILL_NODE(10042, 2170, node2170)
    }
    if (noInit == true) {
        return node2170;
    }
    auto node2164 = GET_SKILL_NODE(2164, PhaseNode_Detect);
    if (node2164 != nullptr) node2170->setType(node2164->getVars().getVariable<int32_t>(2));
    return node2170;
}
//--------------------------------------------------------------------------------
// PlayAnimation
//
REGISTER_REGISTER_SKILL_NODE(10042, 2171) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2171) {
    auto node2171 = GET_SKILL_NODE(2171, PhaseNode_PlayAnimation);
    if (node2171 == nullptr) {
        node2171 = new PhaseNode_PlayAnimation(2171, phase);
        node2171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTrigger, true);
        node2171->setMark(SkillPhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);
        node2171->setTarget(0U);
        node2171->setAnimation("Idle");
        node2171->setParameter("");
        node2171->setValue(false);
        CALL_REGISTER_SKILL_NODE(10042, 2171, node2171)
    }
    if (noInit == true) {
        return node2171;
    }
    return node2171;
}
//--------------------------------------------------------------------------------
// Delay
//
REGISTER_REGISTER_SKILL_NODE(10042, 2172) {
    pnode->resizeTrigger(PhaseNode_Delay::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_SetBool>(PhaseNode_Delay::TRIGGER_DONE, 2175, PhaseNode_SetBool::FUNC_SET, &PhaseNode_SetBool::Set);
}

REGISTER_CREATE_SKILL_NODE(10042, 2172) {
    auto node2172 = GET_SKILL_NODE(2172, PhaseNode_Delay);
    if (node2172 == nullptr) {
        node2172 = new PhaseNode_Delay(2172, phase);
        node2172->setTime(.20f);
        CALL_REGISTER_SKILL_NODE(10042, 2172, node2172)
    }
    if (noInit == true) {
        return node2172;
    }
    return node2172;
}
//--------------------------------------------------------------------------------
// SetBool
//
REGISTER_REGISTER_SKILL_NODE(10042, 2175) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2175) {
    auto node2175 = GET_SKILL_NODE(2175, PhaseNode_SetBool);
    if (node2175 == nullptr) {
        node2175 = new PhaseNode_SetBool(2175, phase);
        node2175->setName("InterruptAnimat");
        node2175->setValue(true);
        CALL_REGISTER_SKILL_NODE(10042, 2175, node2175)
    }
    if (noInit == true) {
        return node2175;
    }
    return node2175;
}
//--------------------------------------------------------------------------------
// RaiseEvent
//
REGISTER_REGISTER_SKILL_NODE(10042, 2176) {
    pnode->resizeTrigger(PhaseNode_RaiseEvent::TRIGGER_MAX);
    pnode->regTrigger<PhaseNode_StartPreInput>(PhaseNode_RaiseEvent::TRIGGER_DONE, 2168, PhaseNode_StartPreInput::FUNC_DO, &PhaseNode_StartPreInput::Do);
}

REGISTER_CREATE_SKILL_NODE(10042, 2176) {
    auto node2176 = GET_SKILL_NODE(2176, PhaseNode_RaiseEvent);
    if (node2176 == nullptr) {
        node2176 = new PhaseNode_RaiseEvent(2176, phase);
        node2176->setEvent("Dead_001");
        node2176->setTarget(0U);
        node2176->setType(PhaseNode_RaiseEvent::RaiseEvent_Type::Interrupt_Skill);
        node2176->setTypeParams(0, 0);
        node2176->setTypeParams(1, 0);
        CALL_REGISTER_SKILL_NODE(10042, 2176, node2176)
    }
    if (noInit == true) {
        return node2176;
    }
    return node2176;
}
//--------------------------------------------------------------------------------
// Detect
//
REGISTER_REGISTER_SKILL_NODE(10042, 2177) {
}

REGISTER_CREATE_SKILL_NODE(10042, 2177) {
    auto node2177 = GET_SKILL_NODE(2177, PhaseNode_Detect);
    if (node2177 == nullptr) {
        node2177 = new PhaseNode_Detect(2177, phase);
        node2177->setSelf(0U);
        node2177->setEvent("Dead_001");
        node2177->setType(PhaseNode_Detect::Detect_Type::Actor_Dead);
        node2177->setMarkID(0);
        CALL_REGISTER_SKILL_NODE(10042, 2177, node2177)
    }
    if (noInit == true) {
        return node2177;
    }
    return node2177;
}

//--------------------------------------------------------------------------------
// SkillCreator_10042
//
class SkillCreator_10042 : public SkillCreator {
public:
    SkillCreator_10042() {}
    virtual ~SkillCreator_10042() {}
    virtual SkillLogic* createSkill(Skill* skill, SkillableActor* owner, uint16_t nId);
    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);
}; // class SkillCreate_10042

//--------------------------------------------------------------------------------
// SkillPhase_10042
//
class SkillPhase_10042 : public SkillPhase {
public:
    SkillPhase_10042(uint16_t id, SkillLogic* logic, uint16_t nFlow) : SkillPhase(id, logic, nFlow) {}
    virtual ~SkillPhase_10042() {}

    virtual SkillPhaseNode* createPhaseNode(uint16_t nId, bool noInit) {
        SWITCH_CREATE_SKILL_START
        CASE_CREATE_SKILL_NODE(10042, 753) // TriggerUpdate
        CASE_CREATE_SKILL_NODE(10042, 916) // StartPhase
        CASE_CREATE_SKILL_NODE(10042, 1657) // PlaySound
        CASE_CREATE_SKILL_NODE(10042, 1982) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10042, 1999) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2003) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10042, 2005) // AttachTo
        CASE_CREATE_SKILL_NODE(10042, 2010) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2012) // EndPhase
        CASE_CREATE_SKILL_NODE(10042, 2016) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10042, 2019) // AttachTo
        CASE_CREATE_SKILL_NODE(10042, 2023) // GetUInt64sValue
        CASE_CREATE_SKILL_NODE(10042, 2029) // SetUInt64
        CASE_CREATE_SKILL_NODE(10042, 2031) // AddSkillBuff
        CASE_CREATE_SKILL_NODE(10042, 2040) // GetLocation
        CASE_CREATE_SKILL_NODE(10042, 2042) // AddSkillBuffs
        CASE_CREATE_SKILL_NODE(10042, 2049) // SetBool
        CASE_CREATE_SKILL_NODE(10042, 2051) // If
        CASE_CREATE_SKILL_NODE(10042, 2055) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10042, 2057) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10042, 2059) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10042, 2061) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10042, 2063) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2065) // SpawnCollider
        CASE_CREATE_SKILL_NODE(10042, 2068) // AttachTo
        CASE_CREATE_SKILL_NODE(10042, 2070) // GetLocation
        CASE_CREATE_SKILL_NODE(10042, 2072) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10042, 2074) // MoveNewPene
        CASE_CREATE_SKILL_NODE(10042, 2085) // DestroyCollider
        CASE_CREATE_SKILL_NODE(10042, 2097) // PlayEffect
        CASE_CREATE_SKILL_NODE(10042, 2100) // PlaySound
        CASE_CREATE_SKILL_NODE(10042, 2102) // Disable
        CASE_CREATE_SKILL_NODE(10042, 2104) // StopEffect
        CASE_CREATE_SKILL_NODE(10042, 2106) // PlayEffect
        CASE_CREATE_SKILL_NODE(10042, 2110) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10042, 2114) // CameraXYZShake
        CASE_CREATE_SKILL_NODE(10042, 2117) // GetLocation
        CASE_CREATE_SKILL_NODE(10042, 2119) // GetInputRotation
        CASE_CREATE_SKILL_NODE(10042, 2121) // AreaCollisionNewPene
        CASE_CREATE_SKILL_NODE(10042, 2127) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2129) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2150) // CreateTriggerNewPene
        CASE_CREATE_SKILL_NODE(10042, 2152) // ActorFilterNewPene
        CASE_CREATE_SKILL_NODE(10042, 2155) // TriggerCheck
        CASE_CREATE_SKILL_NODE(10042, 2158) // All
        CASE_CREATE_SKILL_NODE(10042, 2159) // ResetCD
        CASE_CREATE_SKILL_NODE(10042, 2160) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10042, 2161) // PlaySound
        CASE_CREATE_SKILL_NODE(10042, 2162) // GetActorAttribute
        CASE_CREATE_SKILL_NODE(10042, 2164) // Detect
        CASE_CREATE_SKILL_NODE(10042, 2165) // SwitchToInt
        CASE_CREATE_SKILL_NODE(10042, 2167) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10042, 2168) // StartPreInput
        CASE_CREATE_SKILL_NODE(10042, 2169) // If
        CASE_CREATE_SKILL_NODE(10042, 2170) // IsInterruptType
        CASE_CREATE_SKILL_NODE(10042, 2171) // PlayAnimation
        CASE_CREATE_SKILL_NODE(10042, 2172) // Delay
        CASE_CREATE_SKILL_NODE(10042, 2175) // SetBool
        CASE_CREATE_SKILL_NODE(10042, 2176) // RaiseEvent
        CASE_CREATE_SKILL_NODE(10042, 2177) // Detect
        SWITCH_CREATE_SKILL_END
    }
}; // class SkillPhase_10042

SkillLogic* SkillCreator_10042::createSkill(Skill* skill, SkillableActor* owner, uint16_t nId) {
    //创建执行逻辑
    auto logic = new SkillLogic(nId, owner, skill);
    //设置变量
    Variable_10042_a100423 = logic->getVariables().setVariable<uint64_t>("a100423", 0U);
    Variable_10042_a100424 = logic->getVariables().setVariable<bool>("a100424");
    Variable_10042_a100422 = logic->getVariables().setVariable<int32_t>("a100422", 1);
    Variable_10042_InterruptAnimat = logic->getVariables().setVariable<bool>("InterruptAnimat");
    //创建阶段phase
    auto phase = new SkillPhase_10042(1, logic, 3);
    //设置phase执行器
    phase->setRunPhaseNode(1, 753);
    phase->setRunPhaseNode(2, 916);
    phase->setDetectPhaseNode(3, 2164);
    phase->setDetectPhaseNode(3, 2177);
    //添加设置phase
    logic->addPhase(phase);
    return logic;
}

bool SkillCreator_10042::getSkillExpend(int32_t& nType, int32_t& nValue) {
    return true;
}
} // namespace pvp
