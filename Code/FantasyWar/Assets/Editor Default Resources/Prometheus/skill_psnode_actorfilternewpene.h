#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_ActorFilterNewPene : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_NONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_ActorFilterNewPene(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_ActorFilterNewPene();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF_PLATO(Input, UINT64s, input, 1);
    GETTER_SETTER_PLATO(Hero, bool, hero, 2);
    GETTER_SETTER_PLATO(Minion, bool, minion, 3);
    GETTER_SETTER_PLATO(Destruct, bool, destruct, 4);
    GETTER_SETTER_PLATO(Shield, bool, shield, 5);
    GETTER_SETTER_PLATO(TotalCount, int32_t, totalcount, 6);
    GETTER_SETTER_PLATO(PerCount, int32_t, percount, 7);
    GETTER_SETTER_REF_PLATO(Output, UINT64s, output, 8);
private:
    CLASS_FIELD(input, UINT64s);
    CLASS_FIELD(hero, bool);
    CLASS_FIELD(minion, bool);
    CLASS_FIELD(destruct, bool);
    CLASS_FIELD(shield, bool);
    CLASS_FIELD(totalcount, int32_t);
    CLASS_FIELD(percount, int32_t);
    CLASS_FIELD(output, UINT64s);
};

} // namespace pvp
