#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SwitchToInt : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DEFAULT = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_SWITCH = 0,
    };
public:
    PhaseNode_SwitchToInt(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SwitchToInt();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Switch);

    GETTER_SETTER_PLATO(Selection, int32_t, selection, 1);
private:
    CLASS_FIELD(selection, int32_t);
};

} // namespace pvp
