//
// Created by akimfeopentov on 23.10.22.
//

#include "message.h"

Message::Message(LogType type, std::string message) {
    m_type = type;
    m_msg = message;
}


LogType Message::type() const { return m_type; }

std::ostream &operator<<(std::ostream &stream, const Message &msg) {
    prefix_log prefix=prefix_log(msg.m_type);
    stream << prefix.get_str() << msg.m_msg;
    return stream;
}