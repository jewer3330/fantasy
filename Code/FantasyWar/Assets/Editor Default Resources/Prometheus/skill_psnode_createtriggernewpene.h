#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CreateTriggerNewPene : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_ONCREATED = 0,
        TRIGGER_ONTRIGGED = 1,
        TRIGGER_ONDETECTNONE = 2,
        TRIGGER_MAX = 3,
    };
    enum EType_Func {
        FUNC_CREATE = 0,
    };
    enum CreateTriggerNewPene_Type {
        In = 0,
        Tick = 1,
    };
    enum CreateTriggerNewPene_State {
        Alive = 0,
        Dead = 1,
        All = 2,
    };
    enum CreateTriggerNewPene_CheckFaction {
        Friend = 0,
        Enemy = 1,
        Any = 2,
    };
public:
    PhaseNode_CreateTriggerNewPene(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CreateTriggerNewPene();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Create);

    GETTER_SETTER_PLATO(ColliderID, uint64_t, colliderid, 1);
    GETTER_SETTER_PLATO(Type, int32_t, type, 2);
    GETTER_SETTER_REF_PLATO(TypeParams, Floats, typeparams, 3);
    GETTER_SETTER_PLATO(State, int32_t, state, 4);
    GETTER_SETTER_PLATO(CheckFaction, int32_t, checkfaction, 5);
    GETTER_SETTER_PLATO(OnHero, bool, onhero, 6);
    GETTER_SETTER_PLATO(OnMinion, bool, onminion, 7);
    GETTER_SETTER_PLATO(OnDestruct, bool, ondestruct, 8);
    GETTER_SETTER_PLATO(OnShield, bool, onshield, 9);
    GETTER_SETTER_PLATO(TriggerID, uint64_t, triggerid, 10);
    GETTER_SETTER_REF_PLATO(Other, UINT64s, other, 11);
private:
    CLASS_FIELD(colliderid, uint64_t);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(typeparams, Floats);
    CLASS_FIELD(state, int32_t);
    CLASS_FIELD(checkfaction, int32_t);
    CLASS_FIELD(onhero, bool);
    CLASS_FIELD(onminion, bool);
    CLASS_FIELD(ondestruct, bool);
    CLASS_FIELD(onshield, bool);
    CLASS_FIELD(triggerid, uint64_t);
    CLASS_FIELD(other, UINT64s);
};

} // namespace pvp
