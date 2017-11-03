#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_AttachTo : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_AttachTo(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_AttachTo();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Parent, uint64_t, parent, 1);
    GETTER_SETTER_PLATO(Child, uint64_t, child, 2);
    GETTER_SETTER_PLATO(ChangeRotation, bool, changerotation, 3);
    GETTER_SETTER_PLATO(reentry, bool, reentry, 4);
private:
    CLASS_FIELD(parent, uint64_t);
    CLASS_FIELD(child, uint64_t);
    CLASS_FIELD(changerotation, bool);
    CLASS_FIELD(reentry, bool);
};

} // namespace pvp
