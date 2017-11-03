#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SetMapIF32 : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_SET = 0,
    };
public:
    PhaseNode_SetMapIF32(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SetMapIF32();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Set);

    GETTER_SETTER(Name, std::string, name);
    GETTER_SETTER(Attribute, IFMap, attribute);
private:
    CLASS_FIELD(name, std::string);
    CLASS_FIELD(attribute, IFMap);
};

} // namespace pvp
