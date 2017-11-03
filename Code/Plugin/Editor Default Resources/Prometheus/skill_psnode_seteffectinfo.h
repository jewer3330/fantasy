#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SetEffectInfo : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_SetEffectInfo(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SetEffectInfo();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(EffectID, int32_t, effectid, 1);
    GETTER_SETTER_PLATO(ChangePos, bool, changepos, 2);
    GETTER_SETTER_PLATO(ChangeRotation, bool, changerotation, 3);
    GETTER_SETTER_PLATO(ChangeScale, bool, changescale, 4);
    GETTER_SETTER_PLATO(ChangeColor, bool, changecolor, 5);
    GETTER_SETTER_PLATO(PosX, float, posx, 6);
    GETTER_SETTER_PLATO(PosY, float, posy, 7);
    GETTER_SETTER_PLATO(PosZ, float, posz, 8);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 9);
    GETTER_SETTER_PLATO(ScaleX, float, scalex, 10);
    GETTER_SETTER_PLATO(ScaleY, float, scaley, 11);
    GETTER_SETTER_PLATO(ScaleZ, float, scalez, 12);
    GETTER_SETTER_PLATO(ColorIndex, int32_t, colorindex, 13);
private:
    CLASS_FIELD(effectid, int32_t);
    CLASS_FIELD(changepos, bool);
    CLASS_FIELD(changerotation, bool);
    CLASS_FIELD(changescale, bool);
    CLASS_FIELD(changecolor, bool);
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(scalex, float);
    CLASS_FIELD(scaley, float);
    CLASS_FIELD(scalez, float);
    CLASS_FIELD(colorindex, int32_t);
};

} // namespace pvp
