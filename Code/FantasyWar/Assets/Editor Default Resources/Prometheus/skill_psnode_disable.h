#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Disable : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_CANCEL = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
        FUNC_CANCLE = 1,
    };
public:
    PhaseNode_Disable(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Disable();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);
    DEFINE_INTERFACE(Cancle);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(Move, bool, move, 2);
    GETTER_SETTER_PLATO(Skill, bool, skill, 3);
    GETTER_SETTER_PLATO(Shoot, bool, shoot, 4);
    GETTER_SETTER_PLATO(Time, float, time, 5);
    GETTER_SETTER_PLATO(Rotate, bool, rotate, 6);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(move, bool);
    CLASS_FIELD(skill, bool);
    CLASS_FIELD(shoot, bool);
    CLASS_FIELD(time, float);
    CLASS_FIELD(rotate, bool);
};

} // namespace pvp
