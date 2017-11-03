#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_Detect : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_ON = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_STOP = 0,
    };
    enum Detect_Type {
        Damage = 0,
        Cause_Damage = 1,
        Start_Fire = 2,
        Hold_Fire = 3,
        Bullet_Num = 4,
        Actor_Dead = 5,
        Actor_Spawn = 6,
        Actor_POS = 7,
        Actor_StopMove = 8,
        Kill_Target = 9,
        Attack_Target = 10,
        Start_Skill = 11,
        Interrupt_Skill = 12,
        Divorce_Fight = 13,
        EnegyShiled_Decrease = 14,
        EnegyShiled_Increase = 15,
        Enter_Fight = 16,
        Assistant_Kill = 17,
        Marking = 18,
    };
public:
    PhaseNode_Detect(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_Detect();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    //start接口
    virtual bool start(SkillRunFlow* flow);
    DEFINE_INTERFACE(Stop);

    GETTER_SETTER_PLATO(Self, uint64_t, self, 1);
    GETTER_SETTER_PLATO(Event, std::string, event, 2);
    GETTER_SETTER_PLATO(Type, int32_t, type, 3);
    GETTER_SETTER_REF_PLATO(Vars, VariableList, vars, 4);
    GETTER_SETTER_PLATO(MarkID, int32_t, markid, 5);
private:
    CLASS_FIELD(self, uint64_t);
    CLASS_FIELD(event, std::string);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(vars, VariableList);
    CLASS_FIELD(markid, int32_t);
};

} // namespace pvp
