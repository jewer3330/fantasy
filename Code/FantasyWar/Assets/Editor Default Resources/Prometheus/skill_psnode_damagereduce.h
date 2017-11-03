#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_DamageReduce : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_DamageReduce(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_DamageReduce();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(OriginX, float, originx, 1);
    GETTER_SETTER_PLATO(OriginY, float, originy, 2);
    GETTER_SETTER_PLATO(OriginZ, float, originz, 3);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 4);
    GETTER_SETTER_PLATO(ReductionDist, float, reductiondist, 5);
    GETTER_SETTER_PLATO(Rate, float, rate, 6);
    GETTER_SETTER_PLATO(MinRate, float, minrate, 7);
    GETTER_SETTER_PLATO(Ratio, float, ratio, 8);
private:
    CLASS_FIELD(originx, float);
    CLASS_FIELD(originy, float);
    CLASS_FIELD(originz, float);
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(reductiondist, float);
    CLASS_FIELD(rate, float);
    CLASS_FIELD(minrate, float);
    CLASS_FIELD(ratio, float);
};

} // namespace pvp
