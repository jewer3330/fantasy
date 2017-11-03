#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PlayAnimation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_PLAY = 0,
    };
public:
    PhaseNode_PlayAnimation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PlayAnimation();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Play);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(Animation, std::string, animation, 2);
    GETTER_SETTER_PLATO(Parameter, std::string, parameter, 3);
    GETTER_SETTER_PLATO(Value, bool, value, 4);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(animation, std::string);
    CLASS_FIELD(parameter, std::string);
    CLASS_FIELD(value, bool);
};

} // namespace pvp
