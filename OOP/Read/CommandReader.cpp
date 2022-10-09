//
// Created by akimfeopentov on 18.09.22.
//

#include "CommandReader.h"

char CommandReader::getCommand() const {
        return command;
}

void CommandReader::read() {
    std::cout<<"Введите команду  ";
    std::cin>>command;std::cin.ignore(1251, '\n');
}
