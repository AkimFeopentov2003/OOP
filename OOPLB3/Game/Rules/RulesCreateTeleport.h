//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATETELEPORT_H
#define UNTITLED2_RULESCREATETELEPORT_H
#include "../MapGenerator.h"
#include "../../Events/EventPlayerTeleport.h"
template<int x, int y, int a, int b, int ... next>
class RulesCreateTeleport: public Observable{
public:
    void fill(Field &field) {
        Event *ev = new EventPlayerTeleport(a, b);
        field.get_map()[x][y] = TELEPORT;
        field.get_map()[x][y].setTransformY(a);
        field.get_map()[x][y].setTransformX(b);
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
        if constexpr (sizeof...(next) > 0) {
            RulesCreateTeleport<next...> rul;
            rul.copySubscriptions(this);
            rul.fill(field);
        }
    }
};
#endif //UNTITLED2_RULESCREATETELEPORT_H
