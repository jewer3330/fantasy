#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CameraXYZShake : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
        FUNC_STOP = 1,
    };
public:
    PhaseNode_CameraXYZShake(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CameraXYZShake();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);
    DEFINE_INTERFACE(Stop);

    GETTER_SETTER_PLATO(ShakeStyle, int32_t, shakestyle, 1);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 2);
    GETTER_SETTER_PLATO(X, float, x, 3);
    GETTER_SETTER_PLATO(Y, float, y, 4);
    GETTER_SETTER_PLATO(Z, float, z, 5);
    GETTER_SETTER_PLATO(Duration, float, duration, 6);
    GETTER_SETTER_PLATO(Times, int32_t, times, 7);
private:
    CLASS_FIELD(shakestyle, int32_t);
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(x, float);
    CLASS_FIELD(y, float);
    CLASS_FIELD(z, float);
    CLASS_FIELD(duration, float);
    CLASS_FIELD(times, int32_t);
};

} // namespace pvp
