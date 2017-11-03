#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_LineCollision : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_NONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
    enum LineCollision_State {
        Alive = 0,
        Dead = 1,
        All = 2,
    };
    enum LineCollision_Faction {
        Friend = 0,
        Enemy = 1,
        Any = 2,
    };
public:
    PhaseNode_LineCollision(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_LineCollision();

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
    GETTER_SETTER_PLATO(IncludeSpecial, bool, includespecial, 7);
    GETTER_SETTER_PLATO(FromX, float, fromx, 8);
    GETTER_SETTER_PLATO(FromY, float, fromy, 9);
    GETTER_SETTER_PLATO(FromZ, float, fromz, 10);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 11);
    GETTER_SETTER_PLATO(Range, float, range, 12);
    GETTER_SETTER_PLATO(Penetration, int32_t, penetration, 13);
    GETTER_SETTER_REF_PLATO(Output, UINT64s, output, 14);
    GETTER_SETTER_PLATO(HitPointX, Floats, hitpointx, 15);
    GETTER_SETTER_PLATO(HitPointY, Floats, hitpointy, 16);
    GETTER_SETTER_PLATO(HitPointZ, Floats, hitpointz, 17);
    GETTER_SETTER_PLATO(FartherPointX, float, fartherpointx, 18);
    GETTER_SETTER_PLATO(FartherPointY, float, fartherpointy, 19);
    GETTER_SETTER_PLATO(FartherPointZ, float, fartherpointz, 20);
private:
    CLASS_FIELD(state, int32_t);
    CLASS_FIELD(faction, int32_t);
    CLASS_FIELD(onhero, bool);
    CLASS_FIELD(onminion, bool);
    CLASS_FIELD(ondestruct, bool);
    CLASS_FIELD(onshield, bool);
    CLASS_FIELD(includespecial, bool);
    CLASS_FIELD(fromx, float);
    CLASS_FIELD(fromy, float);
    CLASS_FIELD(fromz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(range, float);
    CLASS_FIELD(penetration, int32_t);
    CLASS_FIELD(output, UINT64s);
    CLASS_FIELD(hitpointx, Floats);
    CLASS_FIELD(hitpointy, Floats);
    CLASS_FIELD(hitpointz, Floats);
    CLASS_FIELD(fartherpointx, float);
    CLASS_FIELD(fartherpointy, float);
    CLASS_FIELD(fartherpointz, float);
};

} // namespace pvp
