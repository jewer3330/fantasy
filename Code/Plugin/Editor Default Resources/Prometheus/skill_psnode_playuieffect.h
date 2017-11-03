#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PlayUIEffect : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_PlayUIEffect(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PlayUIEffect();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Time, float, time, 1);
    GETTER_SETTER_PLATO(Type, int32_t, type, 2);
private:
    CLASS_FIELD(time, float);
    CLASS_FIELD(type, int32_t);
};

} // namespace pvp
