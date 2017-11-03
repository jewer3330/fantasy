#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SpawnActor : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_SpawnActor(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SpawnActor();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 1);
    GETTER_SETTER_PLATO(Time, float, time, 2);
    GETTER_SETTER_PLATO(PosX, float, posx, 3);
    GETTER_SETTER_PLATO(PosY, float, posy, 4);
    GETTER_SETTER_PLATO(PosZ, float, posz, 5);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 6);
    GETTER_SETTER_PLATO(Level, int32_t, level, 7);
    GETTER_SETTER_PLATO(MaxCount, int32_t, maxcount, 8);
    GETTER_SETTER_PLATO(ActorID, uint64_t, actorid, 9);
private:
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(time, float);
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(level, int32_t);
    CLASS_FIELD(maxcount, int32_t);
    CLASS_FIELD(actorid, uint64_t);
};

} // namespace pvp
