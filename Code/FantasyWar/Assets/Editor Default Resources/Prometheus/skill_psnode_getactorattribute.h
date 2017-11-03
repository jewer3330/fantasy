#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetActorAttribute : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_GET = 0,
    };
public:
    PhaseNode_GetActorAttribute(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetActorAttribute();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Get);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_REF_PLATO(Type, INT32s, type, 2);
    GETTER_SETTER_REF_PLATO(Attribute, IIMap, attribute, 3);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(type, INT32s);
    CLASS_FIELD(attribute, IIMap);
};

} // namespace pvp
