#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_TurnToArray : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_TurnToArray(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_TurnToArray();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Single, uint64_t, single, 1);
    GETTER_SETTER_REF_PLATO(Result, UINT64s, result, 2);
private:
    CLASS_FIELD(single, uint64_t);
    CLASS_FIELD(result, UINT64s);
};

} // namespace pvp
