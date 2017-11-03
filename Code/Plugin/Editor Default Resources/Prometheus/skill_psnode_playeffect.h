#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PlayEffect : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
    enum PlayEffect_Type {
        ToPos = 0,
        WithTarget = 1,
    };
public:
    PhaseNode_PlayEffect(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PlayEffect();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(EffectID, int32_t, effectid, 1);
    GETTER_SETTER_PLATO(ChangeColor, bool, changecolor, 2);
    GETTER_SETTER_PLATO(Type, int32_t, type, 3);
    GETTER_SETTER_REF_PLATO(Vars, VariableList, vars, 4);
    GETTER_SETTER_PLATO(Rotation, float, rotation, 5);
    GETTER_SETTER_PLATO(Scale, float, scale, 6);
private:
    CLASS_FIELD(effectid, int32_t);
    CLASS_FIELD(changecolor, bool);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(vars, VariableList);
    CLASS_FIELD(rotation, float);
    CLASS_FIELD(scale, float);
};

} // namespace pvp
