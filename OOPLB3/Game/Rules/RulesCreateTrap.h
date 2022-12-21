//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATETRAP_H
#define UNTITLED2_RULESCREATETRAP_H
#include "../MapGenerator.h"
#include "../../Events/EventMapTrap.h"
template<int x, int y, int ... next>
class RulesCreateTrap: public Observable{
public:
    void fill(Field &field) {
        Event *ev = new EventMapTrap;
        field.get_map()[x][y] = TRAP;
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
        if constexpr (sizeof...(next) > 0)
        {
            RulesCreateTrap<next...> rul;
            rul.copySubscriptions(this);
            rul.fill(field);
        }
    }
};


#endif //UNTITLED2_RULESCREATETRAP_H
