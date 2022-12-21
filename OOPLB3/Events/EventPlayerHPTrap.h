//
// Created by akimfeopentov on 16.10.22.
//

#ifndef UNTITLED2_EVENTPLAYERHPTRAP_H
#define UNTITLED2_EVENTPLAYERHPTRAP_H

#include "EventPlayer.h"
#include "EventStateLoss.h"

class EventPlayerHPTrap : public EventPlayer {
    void eventCell(Field &field);
    ~EventPlayerHPTrap();
};


#endif //UNTITLED2_EVENTPLAYERHPTRAP_H
