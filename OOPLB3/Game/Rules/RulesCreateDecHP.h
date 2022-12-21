//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATEDECHP_H
#define UNTITLED2_RULESCREATEDECHP_H
#include "../MapGenerator.h"
#include "../../Events/EventPlayerHPDec.h"
template<int x, int y, int ... next>
class RulesCreateDecHP: public Observable{
public:
    void fill(Field &field) {
        field.get_map()[x][y] = HP_DEC;
        Event *ev = new EventPlayerHPDec;
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
        if constexpr (sizeof...(next) > 0)
        {
            RulesCreateDecHP<next...> rul;
            rul.copySubscriptions(this);
            rul.fill(field);
        }
    }
};
#endif //UNTITLED2_RULESCREATEDECHP_H
