#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_IncreaseInt : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_INCREASE = 0,
    };
public:
    PhaseNode_IncreaseInt(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_IncreaseInt();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Increase);

    GETTER_SETTER(Name, std::string, name);
    GETTER_SETTER(Value, int32_t, value);
private:
    CLASS_FIELD(name, std::string);
    CLASS_FIELD(value, int32_t);
};

} // namespace pvp
