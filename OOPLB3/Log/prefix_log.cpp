//
// Created by akimfeopentov on 23.10.22.
//

#include "prefix_log.h"


prefix_log::prefix_log(LogType type) {
    switch (type) {
        case LogType::ObjectState:
            str="[Object] ";
            break;
        case LogType::GameState:
            str="[Game]";
            break;
        case LogType::CriticalState:
            str="[Critical]";
            break;
    }
}

std::string prefix_log::get_str() {
    return str;
}