//
// Created by akimfeopentov on 14.10.22.
//

#ifndef UNTITLED2_EVENTPLAYERHPDEC_H
#define UNTITLED2_EVENTPLAYERHPDEC_H
#include "EventPlayer.h"
#include "EventStateLoss.h"

class EventPlayerHPDec: public EventPlayer{
    void eventCell(Field &field);
    ~EventPlayerHPDec();
};


#endif //UNTITLED2_EVENTPLAYERHPDEC_H
