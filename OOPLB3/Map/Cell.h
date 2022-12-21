//
// Created by akimfeopentov on 15.09.22.
//


#ifndef UNTITLED2_CELL_H
#define UNTITLED2_CELL_H

enum TileType {
    STONE, GRASS, TRAP, HP_INC, HP_DEC, TELEPORT, CRASH, FINISH
};

class Cell;

#include "Field.h"
#include "../Events/Event.h"


class Cell {
    TileType characteristic;
    Event *m_event;
    int transformX;
    int transformY;
public:
    Cell(TileType characteristic = GRASS);

    TileType get_characteristic() {
        return characteristic;
    }

    void setCharacteristic(TileType characteristic);
    Cell(const Cell &other);
    Cell &operator=(const Cell &other);

    Cell(Cell &&other);
    Cell &operator=(Cell &&other);

    void triggerEvent(Field &field);

    void setEvent(Event *event);

    void setTransformX(int transformX);
    void setTransformY(int transformY);
    int getTransformX();
    int getTransformY();
};


#endif //UNTITLED2_CELL_H
