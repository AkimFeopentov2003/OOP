//
// Created by akimfeopentov on 12.10.22.
//

#ifndef UNTITLED2_EVENTPLAYERHPINC_H
#define UNTITLED2_EVENTPLAYERHPINC_H

#include "EventPlayer.h"

class EventPlayerHPInc : public EventPlayer {
public:
    void eventCell(Field &field);
    ~EventPlayerHPInc();
};


#endif //UNTITLED2_EVENTPLAYERHPINC_H
