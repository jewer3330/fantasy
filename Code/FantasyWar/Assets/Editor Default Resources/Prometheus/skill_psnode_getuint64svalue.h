#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetUInt64sValue : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetUInt64sValue(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetUInt64sValue();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF_PLATO(Arr, UINT64s, arr, 1);
    GETTER_SETTER_PLATO(Index, int32_t, index, 2);
    GETTER_SETTER_PLATO(Value, uint64_t, value, 3);
private:
    CLASS_FIELD(arr, UINT64s);
    CLASS_FIELD(index, int32_t);
    CLASS_FIELD(value, uint64_t);
};

} // namespace pvp
