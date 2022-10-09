//
// Created by akimfeopentov on 15.09.22.
//
#include "Cell.h"

#ifndef UNTITLED2_FIELD_H
#define UNTITLED2_FIELD_H


class Field {
    int playerPosX;
    int playerPosY;
    int amountCellsX;
    int amountCellsY;
    Cell **map;
public:
    int getPlayerPosX() const;

    void setPlayerPosX(int playerPosX = 0);

    int getPlayerPosY() const;

    void setPlayerPosY(int playerPosY = 0);

    explicit Field(int amountCellsX = 10, int amountCellsY = 10);

    Field(const Field &other);

    Field &operator=(const Field &other);

    Field(Field &&other);
    Field &operator=(Field &&other);

    int get_amountCellsX() const {
        return amountCellsX;
    }

    int get_amountCellsY() const {
        return amountCellsY;
    }

    Cell **get_map() {
        return map;
    }

    ~Field();
};


#endif //UNTITLED2_FIELD_H
