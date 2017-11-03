#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SpawnProjectile : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_SpawnProjectile(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SpawnProjectile();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(DataId, int32_t, dataid, 1);
    GETTER_SETTER_PLATO(PosX, float, posx, 2);
    GETTER_SETTER_PLATO(PosY, float, posy, 3);
    GETTER_SETTER_PLATO(PosZ, float, posz, 4);
    GETTER_SETTER_PLATO(EndPosX, float, endposx, 5);
    GETTER_SETTER_PLATO(EndPosY, float, endposy, 6);
    GETTER_SETTER_PLATO(EndPosZ, float, endposz, 7);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 8);
    GETTER_SETTER_PLATO(MaxCount, int32_t, maxcount, 9);
    GETTER_SETTER_PLATO(ProjectileId, uint64_t, projectileid, 10);
private:
    CLASS_FIELD(dataid, int32_t);
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
    CLASS_FIELD(endposx, float);
    CLASS_FIELD(endposy, float);
    CLASS_FIELD(endposz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(maxcount, int32_t);
    CLASS_FIELD(projectileid, uint64_t);
};

} // namespace pvp
