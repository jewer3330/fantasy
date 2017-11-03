#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_TriggerCheck : public SkillPhaseNode {
public:
    enum EType_Func {
        FUNC_START = 0,
    };
public:
    PhaseNode_TriggerCheck(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_TriggerCheck();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Start);

    GETTER_SETTER_REF_PLATO(Triggers, UINT64s, triggers, 1);
    void setTrigger(uint32_t index, uint64_t value);
private:
    CLASS_FIELD(triggers, UINT64s);
};

} // namespace pvp
