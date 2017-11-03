#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SpawnCollider : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
        FUNC_STOPEXTEND = 1,
    };
    enum SpawnCollider_Type {
        Circle = 0,
        Rect = 1,
        Sector = 2,
    };
public:
    PhaseNode_SpawnCollider(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SpawnCollider();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);
    DEFINE_INTERFACE(StopExtend);

    GETTER_SETTER_PLATO(Mesh, std::string, mesh, 1);
    GETTER_SETTER_PLATO(MeshScale, float, meshscale, 2);
    GETTER_SETTER_PLATO(EffectID, int32_t, effectid, 3);
    GETTER_SETTER_PLATO(EffectScale, float, effectscale, 4);
    GETTER_SETTER_PLATO(Type, int32_t, type, 5);
    GETTER_SETTER_REF_PLATO(TypeParams, Floats, typeparams, 6);
    GETTER_SETTER_PLATO(Time, float, time, 7);
    GETTER_SETTER_PLATO(PosX, float, posx, 8);
    GETTER_SETTER_PLATO(PosY, float, posy, 9);
    GETTER_SETTER_PLATO(PosZ, float, posz, 10);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 11);
    GETTER_SETTER_PLATO(reentry, bool, reentry, 12);
    GETTER_SETTER_PLATO(CheckPeneSound, bool, checkpenesound, 13);
    GETTER_SETTER_PLATO(ColliderID, uint64_t, colliderid, 14);
private:
    CLASS_FIELD(mesh, std::string);
    CLASS_FIELD(meshscale, float);
    CLASS_FIELD(effectid, int32_t);
    CLASS_FIELD(effectscale, float);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(typeparams, Floats);
    CLASS_FIELD(time, float);
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(reentry, bool);
    CLASS_FIELD(checkpenesound, bool);
    CLASS_FIELD(colliderid, uint64_t);
};

} // namespace pvp
