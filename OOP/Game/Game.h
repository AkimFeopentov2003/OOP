//
// Created by akimfeopentov on 18.09.22.
//
#include "iostream"
#include "../Map/FieldView.h"
#include "../Map/Field.h"
#include "../Read/CommandReader.h"
#include "../Controller.h"
#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H


class Game {
public:
    void start();
    void gameCurrent(Field &field);
};


#endif //UNTITLED2_GAME_H
