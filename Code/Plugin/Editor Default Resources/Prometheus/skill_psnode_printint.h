#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PrintInt : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_PRINT = 0,
    };
public:
    PhaseNode_PrintInt(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PrintInt();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Print);

    GETTER_SETTER(Int, int32_t, int);
private:
    CLASS_FIELD(int, int32_t);
};

} // namespace pvp
