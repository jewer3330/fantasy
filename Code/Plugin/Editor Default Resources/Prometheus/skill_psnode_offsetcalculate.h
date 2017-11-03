#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_OffsetCalculate : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_OffsetCalculate(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_OffsetCalculate();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(PosX, float, posx, 1);
    GETTER_SETTER_PLATO(PosY, float, posy, 2);
    GETTER_SETTER_PLATO(PosZ, float, posz, 3);
    GETTER_SETTER_PLATO(OffsetX, float, offsetx, 4);
    GETTER_SETTER_PLATO(OffsetY, float, offsety, 5);
    GETTER_SETTER_PLATO(OffsetZ, float, offsetz, 6);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 7);
    GETTER_SETTER_PLATO(RotOffset, float, rotoffset, 8);
    GETTER_SETTER_PLATO(OutPosX, float, outposx, 9);
    GETTER_SETTER_PLATO(OutPosY, float, outposy, 10);
    GETTER_SETTER_PLATO(OutPosZ, float, outposz, 11);
    GETTER_SETTER_PLATO(OutRotation, float, outrotation, 12);
private:
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
    CLASS_FIELD(offsetx, float);
    CLASS_FIELD(offsety, float);
    CLASS_FIELD(offsetz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(rotoffset, float);
    CLASS_FIELD(outposx, float);
    CLASS_FIELD(outposy, float);
    CLASS_FIELD(outposz, float);
    CLASS_FIELD(outrotation, float);
};

} // namespace pvp
