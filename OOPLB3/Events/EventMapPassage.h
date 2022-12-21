//
// Created by akimfeopentov on 15.10.22.
//

#ifndef UNTITLED2_EVENTMAPPASSAGE_H
#define UNTITLED2_EVENTMAPPASSAGE_H

#include "EventMap.h"

class EventMapPassage : public EventMap {
private:
    int PosCrashX;
    int PosCrashY;
public:
    EventMapPassage(int PosCrashY, int PosCrashX);

    void eventCell(Field &field);
    ~EventMapPassage();
};


#endif //UNTITLED2_EVENTMAPPASSAGE_H
