#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_MoveNewPene : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_STARTMOVE = 0,
        TRIGGER_DONE = 1,
        TRIGGER_BLOCKBYWALL = 2,
        TRIGGER_BLOCKBYSHIELD = 3,
        TRIGGER_MAX = 4,
    };
    enum EType_Func {
        FUNC_DO = 0,
        FUNC_STOP = 1,
    };
    enum MoveNewPene_PeneType {
        Move = 0,
        Projectile = 1,
    };
    enum MoveNewPene_Type {
        Charge = 0,
        Jump = 1,
        Trace = 2,
        Teleport = 3,
    };
    enum MoveNewPene_CheckFaction {
        Enemy = 0,
        Friend = 1,
        All = 2,
    };
public:
    PhaseNode_MoveNewPene(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_MoveNewPene();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);
    DEFINE_INTERFACE(Stop);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(PeneType, int32_t, penetype, 2);
    GETTER_SETTER_PLATO(PeneValue, int32_t, penevalue, 3);
    GETTER_SETTER_PLATO(Type, int32_t, type, 4);
    GETTER_SETTER_REF_PLATO(Vars, VariableList, vars, 5);
    GETTER_SETTER_PLATO(reentry, bool, reentry, 6);
    GETTER_SETTER_PLATO(StopWhenFail, bool, stopwhenfail, 7);
    GETTER_SETTER_PLATO(CheckFaction, int32_t, checkfaction, 8);
    GETTER_SETTER_PLATO(StopTarget, uint64_t, stoptarget, 9);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(penetype, int32_t);
    CLASS_FIELD(penevalue, int32_t);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(vars, VariableList);
    CLASS_FIELD(reentry, bool);
    CLASS_FIELD(stopwhenfail, bool);
    CLASS_FIELD(checkfaction, int32_t);
    CLASS_FIELD(stoptarget, uint64_t);
};

} // namespace pvp
