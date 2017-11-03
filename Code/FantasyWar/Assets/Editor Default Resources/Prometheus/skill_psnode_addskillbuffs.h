#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AddSkillBuffs : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_ADD = 0,
    };
public:
    PhaseNode_AddSkillBuffs(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AddSkillBuffs();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Add);

    GETTER_SETTER_REF_PLATO(ConfigID, INT32s, configid, 1);
    GETTER_SETTER_REF_PLATO(Target, UINT64s, target, 2);
    GETTER_SETTER_REF_PLATO(Attribute, IIMap, attribute, 3);
private:
    CLASS_FIELD(configid, INT32s);
    CLASS_FIELD(target, UINT64s);
    CLASS_FIELD(attribute, IIMap);
};

} // namespace pvp
