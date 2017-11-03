#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AddCurMag : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_ADD = 0,
    };
public:
    PhaseNode_AddCurMag(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AddCurMag();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Add);

    GETTER_SETTER_PLATO(DeltaMag, int32_t, deltamag, 1);
private:
    CLASS_FIELD(deltamag, int32_t);
};

} // namespace pvp
