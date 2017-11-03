#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_WeaponDetect : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_ON = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_STOP = 0,
    };
    enum WeaponDetect_Type {
        Weapon_Hit = 0,
    };
public:
    PhaseNode_WeaponDetect(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_WeaponDetect();

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
    GETTER_SETTER_REF_PLATO(TypeParams, UINT64s, typeparams, 4);
private:
    CLASS_FIELD(self, uint64_t);
    CLASS_FIELD(event, std::string);
    CLASS_FIELD(type, int32_t);
    CLASS_FIELD(typeparams, UINT64s);
};

} // namespace pvp
