#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetMark : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetMark(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetMark();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 1);
    GETTER_SETTER_PLATO(ReleaseTarget, uint64_t, releasetarget, 2);
    GETTER_SETTER_PLATO(ActionTarget, uint64_t, actiontarget, 3);
    GETTER_SETTER_PLATO(Value, int32_t, value, 4);
private:
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(releasetarget, uint64_t);
    CLASS_FIELD(actiontarget, uint64_t);
    CLASS_FIELD(value, int32_t);
};

} // namespace pvp
