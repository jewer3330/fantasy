#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetFloatsValue : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetFloatsValue(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetFloatsValue();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER(Arr, Floats, arr);
    GETTER_SETTER(Index, int32_t, index);
    GETTER_SETTER(Value, float, value);
private:
    CLASS_FIELD(arr, Floats);
    CLASS_FIELD(index, int32_t);
    CLASS_FIELD(value, float);
};

} // namespace pvp
