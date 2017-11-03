#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_StartPreInput : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_StartPreInput(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_StartPreInput();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(DelayTime, float, delaytime, 1);
private:
    CLASS_FIELD(delaytime, float);
};

} // namespace pvp
