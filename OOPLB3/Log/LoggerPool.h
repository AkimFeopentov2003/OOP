//
// Created by akimfeopentov on 31.10.22.
//

#ifndef UNTITLED2_LOGGERPOOL_H
#define UNTITLED2_LOGGERPOOL_H

#include "Logger.h"

class LoggerPool {
public:
    static LoggerPool& getInstance();
    void addLogger(Logger *);
    ~LoggerPool();
private:
    LoggerPool() = default;
    std::vector<Logger *> loggers;
};


#endif //UNTITLED2_LOGGERPOOL_H
