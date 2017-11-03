#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_TypeFilter : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_TypeFilter(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_TypeFilter();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF(Input, UINT64s, input);
    GETTER_SETTER(Hero, bool, hero);
    GETTER_SETTER(Actor, bool, actor);
    GETTER_SETTER_REF(Output, UINT64s, output);
private:
    CLASS_FIELD(input, UINT64s);
    CLASS_FIELD(hero, bool);
    CLASS_FIELD(actor, bool);
    CLASS_FIELD(output, UINT64s);
};

} // namespace pvp
