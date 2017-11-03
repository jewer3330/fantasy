#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_If : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_TRUE = 0,
        TRIGGER_FALSE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_IF = 0,
    };
public:
    PhaseNode_If(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_If();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(If);

    GETTER_SETTER_PLATO(Condition, bool, condition, 1);
private:
    CLASS_FIELD(condition, bool);
};

} // namespace pvp
