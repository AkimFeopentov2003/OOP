//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_MESSAGE_H
#define UNTITLED2_MESSAGE_H
#include "prefix_log.h"
#include "log_type.h"
#include <string>


class Message {
    LogType m_type;
    std::string m_msg;
public:
    Message(LogType type, std::string message);

    LogType type() const;

    friend std::ostream& operator<<(std::ostream& stream, const Message &msg);
};


#endif //UNTITLED2_MESSAGE_H
