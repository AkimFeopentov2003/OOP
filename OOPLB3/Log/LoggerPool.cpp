//
// Created by akimfeopentov on 31.10.22.
//

#include "LoggerPool.h"



void LoggerPool::addLogger(Logger * logger) {
    loggers.push_back(logger);
}

LoggerPool::~LoggerPool() {
    for (Logger *l : loggers)
        delete l;
}

LoggerPool &LoggerPool::getInstance() {
    static LoggerPool lp;
    return lp;
}
