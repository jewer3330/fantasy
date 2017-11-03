#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_GetBBParamUInt64 : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_GetBBParamUInt64(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_GetBBParamUInt64();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(BBName, std::string, bbname, 1);
    GETTER_SETTER_PLATO(Value, uint64_t, value, 2);
private:
    CLASS_FIELD(bbname, std::string);
    CLASS_FIELD(value, uint64_t);
};

} // namespace pvp
