#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetInputObject : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetInputObject(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetInputObject();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(SceneObjId, uint64_t, sceneobjid, 1);
private:
    CLASS_FIELD(sceneobjid, uint64_t);
};

} // namespace pvp
