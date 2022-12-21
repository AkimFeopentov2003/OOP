//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_OBSERVER_H
#define UNTITLED2_OBSERVER_H
#include "message.h"

class Observer {
public:
    virtual void update(const Message &msg) = 0;
};


#endif //UNTITLED2_OBSERVER_H
