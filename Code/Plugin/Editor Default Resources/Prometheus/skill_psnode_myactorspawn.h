#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_MyActorSpawn : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_ONSPAWN = 0,
        TRIGGER_MAX = 1,
    };
public:
    PhaseNode_MyActorSpawn(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_MyActorSpawn();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    //start接口
    virtual bool start(SkillRunFlow* flow);

    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 1);
    GETTER_SETTER_PLATO(ActorID, uint64_t, actorid, 2);
private:
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(actorid, uint64_t);
};

} // namespace pvp
