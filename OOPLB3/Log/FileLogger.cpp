//
// Created by akimfeopentov on 23.10.22.
//
#include <iostream>
#include "FileLogger.h"

FileLogger::FileLogger(const std::string &file) {
    this->file.open(file);
}

void FileLogger::update(const Message &message) {

    if (logTypeAvailable(message.type())) {
        file << message << '\n';
    }
}
FileLogger::~FileLogger() {
    file.close();
}