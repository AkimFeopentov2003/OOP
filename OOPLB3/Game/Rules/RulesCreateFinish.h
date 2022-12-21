//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATEFINISH_H
#define UNTITLED2_RULESCREATEFINISH_H
#include "../MapGenerator.h"
#include "../../Events/EventStateWin.h"
template<int x, int y>
class RulesCreateFinish: public Observable{
public:
    void fill(Field &field) {
        Event *ev = new EventStateWin;
        field.get_map()[x][y] = FINISH;
        ev->copySubscriptions(this);
        field.get_map()[x][y].setEvent(ev);
    }
};
#endif //UNTITLED2_RULESCREATEFINISH_H
