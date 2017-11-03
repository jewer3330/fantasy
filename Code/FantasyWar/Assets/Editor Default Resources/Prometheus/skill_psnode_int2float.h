#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Int2Float : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_Int2Float(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Int2Float();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Int, int32_t, int, 1);
    GETTER_SETTER_PLATO(Float, float, float, 2);
private:
    CLASS_FIELD(int, int32_t);
    CLASS_FIELD(float, float);
};

} // namespace pvp
