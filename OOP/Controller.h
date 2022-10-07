//
// Created by akimfeopentov on 18.09.22.
//
#include "Map/Field.h"
#include "Map/FieldView.h"
#include "Player/Player.h"
#include "Read/CommandReader.h"

#ifndef UNTITLED2_CONTROLER_H
#define UNTITLED2_CONTROLER_H


class Controller{
public:
    Controller(CommandReader &cur,Field &field);
    void action(CommandReader &cur,Field &field);
};


#endif //UNTITLED2_CONTROLER_H
