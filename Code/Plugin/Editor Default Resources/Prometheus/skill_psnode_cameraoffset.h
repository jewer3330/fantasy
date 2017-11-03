#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CameraOffset : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_CameraOffset(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CameraOffset();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(OffsetX, float, offsetx, 1);
    GETTER_SETTER_PLATO(OffsetY, float, offsety, 2);
    GETTER_SETTER_PLATO(OffsetZ, float, offsetz, 3);
    GETTER_SETTER_PLATO(Speed, float, speed, 4);
private:
    CLASS_FIELD(offsetx, float);
    CLASS_FIELD(offsety, float);
    CLASS_FIELD(offsetz, float);
    CLASS_FIELD(speed, float);
};

} // namespace pvp
