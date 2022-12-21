//
// Created by akimfeopentov on 12.12.22.
//

#ifndef UNTITLED2_RULESCREATEHP_H
#define UNTITLED2_RULESCREATEHP_H
#include "../MapGenerator.h"

template <int hp>
class RulesCreateHP: public Observable{
public:
    void fill(Field &field) {
        field.getPlayer()->setHp(hp);
    }
};


#endif //UNTITLED2_RULESCREATEHP_H
