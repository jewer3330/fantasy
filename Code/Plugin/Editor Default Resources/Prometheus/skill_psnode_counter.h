#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Counter : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_REACHED = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_COUNT = 0,
    };
public:
    PhaseNode_Counter(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Counter();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Count);

    GETTER_SETTER(Increase, int32_t, increase);
    GETTER_SETTER(Start, int32_t, start);
    GETTER_SETTER(End, int32_t, end);
private:
    CLASS_FIELD(increase, int32_t);
    CLASS_FIELD(start, int32_t);
    CLASS_FIELD(end, int32_t);
};

} // namespace pvp
