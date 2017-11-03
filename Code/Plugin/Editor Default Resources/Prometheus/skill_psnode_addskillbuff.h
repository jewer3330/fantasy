#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AddSkillBuff : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_ADD = 0,
    };
public:
    PhaseNode_AddSkillBuff(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AddSkillBuff();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Add);

    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 1);
    GETTER_SETTER_REF_PLATO(ConfigIDs, INT32s, configids, 2);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 3);
    GETTER_SETTER_REF_PLATO(Attribute, IIMap, attribute, 4);
private:
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(configids, INT32s);
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(attribute, IIMap);
};

} // namespace pvp
