#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_FindSkillBuff : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_FindSkillBuff(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_FindSkillBuff();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(SelfTarget, uint64_t, selftarget, 1);
    GETTER_SETTER_PLATO(DetectTarget, uint64_t, detecttarget, 2);
    GETTER_SETTER_PLATO(ConfigID, int32_t, configid, 3);
    GETTER_SETTER_PLATO(Result, bool, result, 4);
private:
    CLASS_FIELD(selftarget, uint64_t);
    CLASS_FIELD(detecttarget, uint64_t);
    CLASS_FIELD(configid, int32_t);
    CLASS_FIELD(result, bool);
};

} // namespace pvp
