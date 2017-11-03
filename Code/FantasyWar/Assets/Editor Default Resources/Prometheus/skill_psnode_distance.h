#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Distance : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_Distance(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Distance();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(AX, float, ax, 1);
    GETTER_SETTER_PLATO(AY, float, ay, 2);
    GETTER_SETTER_PLATO(BX, float, bx, 3);
    GETTER_SETTER_PLATO(BY, float, by, 4);
    GETTER_SETTER_PLATO(Result, float, result, 5);
private:
    CLASS_FIELD(ax, float);
    CLASS_FIELD(ay, float);
    CLASS_FIELD(bx, float);
    CLASS_FIELD(by, float);
    CLASS_FIELD(result, float);
};

} // namespace pvp
