#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_LimitInputRotation : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_LimitInputRotation(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_LimitInputRotation();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER(Rotation, float, rotation);
    GETTER_SETTER(LimitDegree, float, limitdegree);
private:
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(limitdegree, float);
};

} // namespace pvp
