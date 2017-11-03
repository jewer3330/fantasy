#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AreaCollisionNewPene : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_NONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
    enum AreaCollisionNewPene_State {
        Alive = 0,
        Dead = 1,
        All = 2,
    };
    enum AreaCollisionNewPene_Faction {
        Friend = 0,
        Enemy = 1,
        Any = 2,
    };
    enum AreaCollisionNewPene_Type {
        Circle = 0,
        Rect = 1,
        Sector = 2,
    };
public:
    PhaseNode_AreaCollisionNewPene(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AreaCollisionNewPene();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(State, int32_t, state, 1);
    GETTER_SETTER_PLATO(Faction, int32_t, faction, 2);
    GETTER_SETTER_PLATO(OnHero, bool, onhero, 3);
    GETTER_SETTER_PLATO(OnMinion, bool, onminion, 4);
    GETTER_SETTER_PLATO(OnDestruct, bool, ondestruct, 5);
    GETTER_SETTER_PLATO(OnShield, bool, onshield, 6);
    GETTER_SETTER_PLATO(Type, int32_t, type, 7);
    GETTER_SETTER_REF_PLATO(TypeParams, Floats, typeparams, 8);
    GETTER_SETTER_PLATO(PositionX, float, positionx, 9);
    GETTER_SETTER_PLATO(PositionY, float, positiony, 10);
    GETTER_SETTER_PLATO(PositionZ, float, positionz, 11);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 12);
    GETTER_SETTER_REF_PLATO(Colliders, UINT64s, colliders, 13);
private:
    CLASS_FIELD(state, int32_t);
    CLASS_FIELD(faction, int32_t);
    CLASS_FIELD(onhero, bool);
    CLASS_FIELD(onminion, bool);
    CLASS_FIELD(ondestruct, bool);
    CLASS_FIELD(onshield, bool);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(typeparams, Floats);
    CLASS_FIELD(positionx, float);
    CLASS_FIELD(positiony, float);
    CLASS_FIELD(positionz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(colliders, UINT64s);
};

} // namespace pvp
