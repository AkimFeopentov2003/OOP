//
// Created by akimfeopentov on 14.10.22.
//

#ifndef UNTITLED2_EVENTMAPTRAP_H
#define UNTITLED2_EVENTMAPTRAP_H

#include "EventMap.h"
#include "EventPlayerHPTrap.h"
#include "EventStateLoss.h"

class EventMapTrap : public EventMap {
public:
    void eventCell(Field &field);
    ~EventMapTrap();
};


#endif //UNTITLED2_EVENTMAPTRAP_H
