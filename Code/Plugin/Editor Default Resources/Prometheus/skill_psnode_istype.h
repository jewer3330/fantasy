#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_IsType : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_IsType(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_IsType();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER(Input, uint64_t, input);
    GETTER_SETTER(Hero, bool, hero);
    GETTER_SETTER(Actor, bool, actor);
private:
    CLASS_FIELD(input, uint64_t);
    CLASS_FIELD(hero, bool);
    CLASS_FIELD(actor, bool);
};

} // namespace pvp
