#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_UnlockSkill : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_UnlockSkill(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_UnlockSkill();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(SkillID, int32_t, skillid, 1);
private:
    CLASS_FIELD(skillid, int32_t);
};

} // namespace pvp
