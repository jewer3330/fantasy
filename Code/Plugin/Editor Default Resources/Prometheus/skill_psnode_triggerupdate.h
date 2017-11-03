#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_TriggerUpdate : public SkillPhaseNode {
public:
public:
    PhaseNode_TriggerUpdate(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_TriggerUpdate();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    //start接口
    virtual bool start(SkillRunFlow* flow);

    void addTriggerCheck(PhaseNode_TriggerCheck* check);

private:
};

} // namespace pvp
