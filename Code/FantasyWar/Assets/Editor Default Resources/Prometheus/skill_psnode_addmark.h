#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AddMark : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_ADD = 0,
    };
public:
    PhaseNode_AddMark(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AddMark();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Add);

    GETTER_SETTER_REF_PLATO(ConfigIDs, INT32s, configids, 1);
    GETTER_SETTER_PLATO(ReleaseTarget, uint64_t, releasetarget, 2);
    GETTER_SETTER_REF_PLATO(ActionTarget, UINT64s, actiontarget, 3);
private:
    CLASS_FIELD(configids, INT32s);
    CLASS_FIELD(releasetarget, uint64_t);
    CLASS_FIELD(actiontarget, UINT64s);
};

} // namespace pvp
