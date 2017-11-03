#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CompareInt : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_LESS = 0,
        TRIGGER_EQUAL = 1,
        TRIGGER_GREATER = 2,
        TRIGGER_MAX = 3,
    };
    enum EType_Func {
        FUNC_COMPARE = 0,
    };
public:
    PhaseNode_CompareInt(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CompareInt();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Compare);

    GETTER_SETTER_PLATO(A, int32_t, a, 1);
    GETTER_SETTER_PLATO(B, int32_t, b, 2);
private:
    CLASS_FIELD(a, int32_t);
    CLASS_FIELD(b, int32_t);
};

} // namespace pvp
