#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_For : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DO = 0,
        TRIGGER_DONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_START = 0,
        FUNC_CONTINUE = 1,
    };
public:
    PhaseNode_For(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_For();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Start);
    DEFINE_INTERFACE(Continue);

    GETTER_SETTER_PLATO(Begin, int32_t, begin, 1);
    GETTER_SETTER_PLATO(Increase, int32_t, increase, 2);
    GETTER_SETTER_PLATO(End, int32_t, end, 3);
    GETTER_SETTER_PLATO(Value, int32_t, value, 4);
    GETTER_SETTER_PLATO(FID, int32_t, fid, 5);
private:
    CLASS_FIELD(begin, int32_t);
    CLASS_FIELD(increase, int32_t);
    CLASS_FIELD(end, int32_t);
    CLASS_FIELD(value, int32_t);
    CLASS_FIELD(fid, int32_t);
};

} // namespace pvp
