//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_FILELOGGER_H
#define UNTITLED2_FILELOGGER_H

#include "Logger.h"
#include "message.h"
#include <fstream>


class FileLogger : public Logger {
    std::ofstream file;
public:
    FileLogger(const std::string &file);
    void update(const Message &message);
    ~FileLogger();
};


#endif //UNTITLED2_FILELOGGER_H
