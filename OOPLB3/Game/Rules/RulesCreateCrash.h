//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATECRASH_H
#define UNTITLED2_RULESCREATECRASH_H

#include "../MapGenerator.h"
#include "../../Events/EventMapPassage.h"
template<int x, int y, int a, int b, int ... next>
class RulesCreatePassage: public Observable{
public:
    void fill(Field &field) {
        Event *ev = new EventMapPassage(a, b);
        field.get_map()[x][y] = CRASH;
        field.get_map()[x][y].setTransformY(a);
        field.get_map()[x][y].setTransformX(b);
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
        if constexpr (sizeof...(next) > 0) {
            RulesCreatePassage<next...> rul;
            rul.copySubscriptions(this);
            rul.fill(field);
        }
    }
};
#endif //UNTITLED2_RULESCREATECRASH_H
