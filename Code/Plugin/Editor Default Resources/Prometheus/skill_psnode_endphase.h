#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_EndPhase : public SkillPhaseNode {
public:
    enum EType_Func {
        FUNC_STOP = 0,
    };
public:
    PhaseNode_EndPhase(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_EndPhase();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Stop);

private:
};

} // namespace pvp
