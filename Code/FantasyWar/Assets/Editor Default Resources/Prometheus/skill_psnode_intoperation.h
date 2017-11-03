#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_IntOperation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_OPERATION = 0,
    };
    enum IntOperation_Method {
        Add = 0,
        Sub = 1,
        Multi = 2,
        Divis = 3,
    };
public:
    PhaseNode_IntOperation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_IntOperation();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Operation);

    GETTER_SETTER_PLATO(Base, int32_t, base, 1);
    GETTER_SETTER_PLATO(Value, int32_t, value, 2);
    GETTER_SETTER_PLATO(Method, int32_t, method, 3);
    GETTER_SETTER_PLATO(Final, int32_t, final, 4);
private:
    CLASS_FIELD(base, int32_t);
    CLASS_FIELD(value, int32_t);
    CLASS_FIELD(method, int32_t);
    CLASS_FIELD(final, int32_t);
};

} // namespace pvp
