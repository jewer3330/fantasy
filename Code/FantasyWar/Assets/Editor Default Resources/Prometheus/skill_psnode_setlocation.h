#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SetLocation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_SetLocation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SetLocation();

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
    GETTER_SETTER_PLATO(VX, float, vx, 4);
    GETTER_SETTER_PLATO(VY, float, vy, 5);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(x, float);
    CLASS_FIELD(y, float);
    CLASS_FIELD(vx, float);
    CLASS_FIELD(vy, float);
};

} // namespace pvp
