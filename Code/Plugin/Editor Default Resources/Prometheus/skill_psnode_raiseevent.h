#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_RaiseEvent : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
    enum RaiseEvent_Type {
        Interrupt_Skill = 0,
    };
public:
    PhaseNode_RaiseEvent(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_RaiseEvent();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Event, std::string, event, 1);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 2);
    GETTER_SETTER_PLATO(Type, int32_t, type, 3);
    GETTER_SETTER_REF_PLATO(TypeParams, INT32s, typeparams, 4);
private:
    CLASS_FIELD(event, std::string);
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(typeparams, INT32s);
};

} // namespace pvp
