#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PrintVector : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_PrintVector(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PrintVector();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER(X, float, x);
    GETTER_SETTER(Y, float, y);
    GETTER_SETTER(Z, float, z);
private:
    CLASS_FIELD(x, float);
    CLASS_FIELD(y, float);
    CLASS_FIELD(z, float);
};

} // namespace pvp
