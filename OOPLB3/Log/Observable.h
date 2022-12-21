//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_OBSERVABLE_H
#define UNTITLED2_OBSERVABLE_H
#include "Observer.h"
#include <vector>

class Observable {
    std::vector< Observer * > list;
public:
    void subscribe(Observer *observer);
    void unsubscribe(Observer *observer);
    void notify(const Message &message);
    void copySubscriptions(Observable *other);
};


#endif //UNTITLED2_OBSERVABLE_H
