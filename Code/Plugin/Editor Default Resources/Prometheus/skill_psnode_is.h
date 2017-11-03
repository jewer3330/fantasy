#pragma once

#include "node.hpp"
#include "skill.h"

namespace pvp {

class PhaseNode_IS : public SkillPhaseNode {
public:
    enum EType_Trigger {
        TRIGGER_TRUE = 0,
        TRIGGER_FALSE = 1,
    };
    enum EType_Func {
        FUNC_DO = 0,
    };
public:
    PhaseNode_IS(uint16_t id, SkillPhase* phase);
    virtual ~PhaseNode_IS();

    //节点更新
    virtual void update(SkillRunFlow* flow, uint32_t ms);

    //序列化
    virtual void serializeNode(const PlatoPhaseNodeSync* sync);

    //反序列化
    virtual void deSerializeNode(PlatoPhaseNodeSync* sync);

    DEFINE_INTERFACE(Do);

    GETTER_SETTER(Target, uint64_t, target);
    GETTER_SETTER(FriendHero, bool, friendhero);
    GETTER_SETTER(FriendActor, bool, friendactor);
    GETTER_SETTER(EnemyHero, bool, enemyhero);
    GETTER_SETTER(EnemyActor, bool, enemyactor);
private:
    CLASS_FIELD(target, uint64_t);
    CLASS_FIELD(friendhero, bool);
    CLASS_FIELD(friendactor, bool);
    CLASS_FIELD(enemyhero, bool);
    CLASS_FIELD(enemyactor, bool);
};

} // namespace pvp
