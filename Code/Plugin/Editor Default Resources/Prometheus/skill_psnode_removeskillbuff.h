#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_RemoveSkillBuff : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_REMOVE = 0,
    };
public:
    PhaseNode_RemoveSkillBuff(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_RemoveSkillBuff();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Remove);

    GETTER_SETTER_PLATO(BuffID, uint64_t, buffid, 1);
    GETTER_SETTER_REF_PLATO(BuffIDs, UINT64s, buffids, 2);
    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 3);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 4);
private:
    CLASS_FIELD(buffid, uint64_t);
    CLASS_FIELD(buffids, UINT64s);
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(target, uint64_t);
};

} // namespace pvp
