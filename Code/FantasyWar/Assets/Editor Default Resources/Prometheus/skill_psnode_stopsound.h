#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_StopSound : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_STOP = 0,
    };
public:
    PhaseNode_StopSound(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_StopSound();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Stop);

    GETTER_SETTER_PLATO(SoundID, std::string, soundid, 1);
private:
    CLASS_FIELD(soundid, std::string);
};

} // namespace pvp
