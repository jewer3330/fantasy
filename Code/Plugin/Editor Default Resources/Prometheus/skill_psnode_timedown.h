#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_TimeDown : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_CANCELDONE = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
        FUNC_CANCEL = 1,
    };
public:
    PhaseNode_TimeDown(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_TimeDown();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);
    DEFINE_INTERFACE(Cancel);

    GETTER_SETTER_PLATO(Time, float, time, 1);
    GETTER_SETTER_PLATO(Num, int32_t, num, 2);
    GETTER_SETTER_PLATO(IsImmediateFirst, bool, isimmediatefirst, 3);
    GETTER_SETTER_PLATO(OutTime, float, outtime, 4);
    GETTER_SETTER_PLATO(LeftNum, int32_t, leftnum, 5);
private:
    CLASS_FIELD(time, float);
    CLASS_FIELD(num, int32_t);
    CLASS_FIELD(isimmediatefirst, bool);
    CLASS_FIELD(outtime, float);
    CLASS_FIELD(leftnum, int32_t);
};

} // namespace pvp
