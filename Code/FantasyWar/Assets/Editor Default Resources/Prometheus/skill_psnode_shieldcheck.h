#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_ShieldCheck : public SkillPhaseNode {
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
    PhaseNode_ShieldCheck(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_ShieldCheck();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF(Targets, UINT64s, targets);
    GETTER_SETTER(OffsetX, float, offsetx);
    GETTER_SETTER(OffsetY, float, offsety);
    GETTER_SETTER(OffsetOri, float, offsetori);
    GETTER_SETTER(ColliderId, uint64_t, colliderid);
    GETTER_SETTER_REF(Output, UINT64s, output);
private:
    CLASS_FIELD(targets, UINT64s);
    CLASS_FIELD(offsetx, float);
    CLASS_FIELD(offsety, float);
    CLASS_FIELD(offsetori, float);
    CLASS_FIELD(colliderid, uint64_t);
    CLASS_FIELD(output, UINT64s);
};

} // namespace pvp
