#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_FilterSelf : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_HAVESELF = 0,
        TRIGGER_NOSELF = 1,
        TRIGGER_MAX = 2,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_FilterSelf(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_FilterSelf();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF_PLATO(Targets, UINT64s, targets, 1);
    GETTER_SETTER_PLATO(SelfTarget, uint64_t, selftarget, 2);
    GETTER_SETTER_REF_PLATO(OtherTargets, UINT64s, othertargets, 3);
private:
    CLASS_FIELD(targets, UINT64s);
    CLASS_FIELD(selftarget, uint64_t);
    CLASS_FIELD(othertargets, UINT64s);
};

} // namespace pvp
