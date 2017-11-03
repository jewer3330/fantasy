#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetLocation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetLocation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetLocation();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(X, float, x, 2);
    GETTER_SETTER_PLATO(Y, float, y, 3);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(x, float);
    CLASS_FIELD(y, float);
};

} // namespace pvp
