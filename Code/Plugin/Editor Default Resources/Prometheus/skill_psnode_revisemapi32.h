#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_ReviseMapI32 : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_ReviseMapI32(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_ReviseMapI32();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_REF_PLATO(InAttri, IIMap, inattri, 1);
    GETTER_SETTER_REF_PLATO(OutAttri, IIMap, outattri, 2);
private:
    CLASS_FIELD(inattri, IIMap);
    CLASS_FIELD(outattri, IIMap);
};

} // namespace pvp
