//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_CONSOLLOGGER_H
#define UNTITLED2_CONSOLLOGGER_H

#include "Logger.h"
#include "message.h"

class ConsoleLogger : public Logger {
public:
    void update(const Message &message);
};


#endif //UNTITLED2_CONSOLLOGGER_H
