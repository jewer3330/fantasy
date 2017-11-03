#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Delay : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DELAY = 0,
    };
public:
    PhaseNode_Delay(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Delay();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Delay);

    GETTER_SETTER_PLATO(Time, float, time, 1);
private:
    CLASS_FIELD(time, float);
};

} // namespace pvp
