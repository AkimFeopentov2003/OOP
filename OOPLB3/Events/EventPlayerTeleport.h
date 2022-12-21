//
// Created by akimfeopentov on 15.10.22.
//

#ifndef UNTITLED2_EVENTPLAYERTELEPORT_H
#define UNTITLED2_EVENTPLAYERTELEPORT_H

#include "EventPlayer.h"

class EventPlayerTeleport : public EventPlayer {
private:
    int PosTeleportX;
    int PosTeleportY;
public:
    EventPlayerTeleport(int y, int x);
    int getPosTeleportX();
    int getPosTeleportY();
    void eventCell(Field &field);
    ~EventPlayerTeleport();
};


#endif //UNTITLED2_EVENTPLAYERTELEPORT_H
