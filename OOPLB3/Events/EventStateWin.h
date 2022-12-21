//
// Created by akimfeopentov on 14.10.22.
//

#ifndef UNTITLED2_EVENTSTATEWIN_H
#define UNTITLED2_EVENTSTATEWIN_H

#include "EventState.h"

class EventStateWin : public EventState {
public:
    void eventCell(Field &field);
    ~EventStateWin();
};


#endif //UNTITLED2_EVENTSTATEWIN_H
