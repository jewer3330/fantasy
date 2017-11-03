#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CompareFloat : public SkillPhaseNode {
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
    PhaseNode_CompareFloat(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CompareFloat();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Compare);

    GETTER_SETTER_PLATO(A, float, a, 1);
    GETTER_SETTER_PLATO(B, float, b, 2);
private:
    CLASS_FIELD(a, float);
    CLASS_FIELD(b, float);
};

} // namespace pvp
