#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetLineRotation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetLineRotation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetLineRotation();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(StartX, float, startx, 1);
    GETTER_SETTER_PLATO(StartY, float, starty, 2);
    GETTER_SETTER_PLATO(EndX, float, endx, 3);
    GETTER_SETTER_PLATO(EndY, float, endy, 4);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 5);
private:
    CLASS_FIELD(startx, float);
    CLASS_FIELD(starty, float);
    CLASS_FIELD(endx, float);
    CLASS_FIELD(endy, float);
    CLASS_FIELD(rotation, float);
};

} // namespace pvp
