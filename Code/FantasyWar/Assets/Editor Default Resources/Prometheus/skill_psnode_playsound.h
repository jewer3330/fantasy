#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_PlaySound : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_PLAY = 0,
    };
public:
    PhaseNode_PlaySound(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_PlaySound();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Play);

    GETTER_SETTER_PLATO(SoundID, std::string, soundid, 1);
    GETTER_SETTER_PLATO(Target, uint64_t, target, 2);
    GETTER_SETTER_PLATO(UsePos, bool, usepos, 3);
    GETTER_SETTER_PLATO(PosX, float, posx, 4);
    GETTER_SETTER_PLATO(PosY, float, posy, 5);
    GETTER_SETTER_PLATO(PosZ, float, posz, 6);
private:
    CLASS_FIELD(soundid, std::string);
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(usepos, bool);
    CLASS_FIELD(posx, float);
    CLASS_FIELD(posy, float);
    CLASS_FIELD(posz, float);
};

} // namespace pvp
