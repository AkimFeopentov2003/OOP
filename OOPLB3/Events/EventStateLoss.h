//
// Created by akimfeopentov on 14.10.22.
//

#ifndef UNTITLED2_EVENTSTATELOSS_H
#define UNTITLED2_EVENTSTATELOSS_H
#include "EventState.h"

class EventStateLoss :public EventState{
    void eventCell(Field &field);
    ~EventStateLoss();
};


#endif //UNTITLED2_EVENTSTATELOSS_H
