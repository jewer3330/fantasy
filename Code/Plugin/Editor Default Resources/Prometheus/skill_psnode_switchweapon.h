#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_SwitchWeapon : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_DONE = 0,
        TRIGGER_MAX = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_SwitchWeapon(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_SwitchWeapon();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER_PLATO(Target, uint64_t, target, 1);
    GETTER_SETTER_PLATO(Time, float, time, 2);
    GETTER_SETTER_PLATO(Shots, int32_t, shots, 3);
    GETTER_SETTER_PLATO(WeaponID, int32_t, weaponid, 4);
    GETTER_SETTER_PLATO(SaveMag, bool, savemag, 5);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(time, float);
    CLASS_FIELD(shots, int32_t);
    CLASS_FIELD(weaponid, int32_t);
    CLASS_FIELD(savemag, bool);
};

} // namespace pvp
