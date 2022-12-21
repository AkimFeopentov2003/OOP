//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_PREFIX_LOG_H
#define UNTITLED2_PREFIX_LOG_H

#include "log_type.h"
#include <string>

class prefix_log {
    std::string str;
public:
    prefix_log(LogType type);
    std::string get_str();
};


#endif //UNTITLED2_PREFIX_LOG_H
