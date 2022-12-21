//
// Created by akimfeopentov on 31.10.22.
//

#ifndef UNTITLED2_LEVEL_H
#define UNTITLED2_LEVEL_H

#include "../Map/Field.h"

class Level : public Observable {
public:
    virtual void start() = 0;
    virtual void gameCurrent(Field &field) = 0;
};


#endif //UNTITLED2_LEVEL_H
