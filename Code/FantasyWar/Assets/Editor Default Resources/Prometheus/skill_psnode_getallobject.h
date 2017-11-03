#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetAllObject : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
    enum GetAllObject_State {
        Alive = 0,
        Dead = 1,
        StateAll = 2,
    };
    enum GetAllObject_CheckFaction {
        Friend = 0,
        Enemy = 1,
        All = 2,
    };
public:
    PhaseNode_GetAllObject(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetAllObject();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(State, int32_t, state, 1);
    GETTER_SETTER_PLATO(CheckFaction, int32_t, checkfaction, 2);
    GETTER_SETTER_PLATO(OnHero, bool, onhero, 3);
    GETTER_SETTER_PLATO(OnMinion, bool, onminion, 4);
    GETTER_SETTER_PLATO(OnDestruct, bool, ondestruct, 5);
    GETTER_SETTER_REF_PLATO(OutPut, UINT64s, output, 6);
private:
    CLASS_FIELD(state, int32_t);
    CLASS_FIELD(checkfaction, int32_t);
    CLASS_FIELD(onhero, bool);
    CLASS_FIELD(onminion, bool);
    CLASS_FIELD(ondestruct, bool);
    CLASS_FIELD(output, UINT64s);
};

} // namespace pvp
