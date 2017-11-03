#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_CameraShake : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_CameraShake(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_CameraShake();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(Frequency, float, frequency, 2);
    GETTER_SETTER_PLATO(Amplitude, float, amplitude, 3);
    GETTER_SETTER_PLATO(Duration, float, duration, 4);
    GETTER_SETTER_PLATO(Falloff, bool, falloff, 5);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(frequency, float);
    CLASS_FIELD(amplitude, float);
    CLASS_FIELD(duration, float);
    CLASS_FIELD(falloff, bool);
};

} // namespace pvp
