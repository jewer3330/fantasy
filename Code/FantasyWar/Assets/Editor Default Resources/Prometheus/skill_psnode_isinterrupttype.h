#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_IsInterruptType : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_NONE = 0,
        TRIGGER_BUFF = 1,
        TRIGGER_RAISE = 2,
        TRIGGER_POSCHANGE = 3,
        TRIGGER_STARTFIRE = 4,
        TRIGGER_USESKILL = 5,
        TRIGGER_STARTAIM = 6,
        TRIGGER_STARTRELOAD = 7,
        TRIGGER_MAX = 8,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_IsInterruptType(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_IsInterruptType();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Type, int32_t, type, 1);
private:
    CLASS_FIELD(type, int32_t);
};

} // namespace pvp
