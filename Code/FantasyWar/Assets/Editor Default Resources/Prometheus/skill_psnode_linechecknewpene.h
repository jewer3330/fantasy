#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_LineCheckNewPene : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_NONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_LineCheckNewPene(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_LineCheckNewPene();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF_PLATO(Targets, UINT64s, targets, 1);
    GETTER_SETTER_PLATO(FromX, float, fromx, 2);
    GETTER_SETTER_PLATO(FromY, float, fromy, 3);
    GETTER_SETTER_PLATO(PeneProjectile, int32_t, peneprojectile, 4);
    GETTER_SETTER_REF_PLATO(Output, UINT64s, output, 5);
private:
    CLASS_FIELD(targets, UINT64s);
    CLASS_FIELD(fromx, float);
    CLASS_FIELD(fromy, float);
    CLASS_FIELD(peneprojectile, int32_t);
    CLASS_FIELD(output, UINT64s);
};

} // namespace pvp
