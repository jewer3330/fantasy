#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_All : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_CHECK1 = 0,
        FUNC_CHECK2 = 1,
    };
public:
    PhaseNode_All(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_All();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Check1);
    DEFINE_INTERFACE(Check2);

private:
};

} // namespace pvp
