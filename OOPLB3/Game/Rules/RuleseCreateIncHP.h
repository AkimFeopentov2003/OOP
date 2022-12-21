//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESECREATEINCHP_H
#define UNTITLED2_RULESECREATEINCHP_H
#include "../MapGenerator.h"
#include "../../Events/EventPlayerHPInc.h"
template<int x, int y, int ... next>
class RulesCreateIncHP:public Observable{
public:
    void fill(Field &field) {
        Event *ev = new EventPlayerHPInc;
        field.get_map()[x][y] = HP_INC;
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
        if constexpr (sizeof...(next) > 0)
        {
            RulesCreateIncHP<next...> rul;
            rul.copySubscriptions(this);
            rul.fill(field);
        }
    }
};
#endif //UNTITLED2_RULESECREATEINCHP_H
