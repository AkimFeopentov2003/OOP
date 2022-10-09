//
// Created by akimfeopentov on 15.09.22.
//
#include "../Events/Event.h"

#ifndef UNTITLED2_CELL_H
#define UNTITLED2_CELL_H
enum TileType {
    STONE, GRASS
};
class Cell {
    TileType characteristic;
    Event event;
public:
    Cell(TileType characteristic=GRASS){
        this->characteristic=characteristic;
        void cellEvent();
    }
    char get_characteristic(){
        return characteristic;
    }
    void setCharacteristic(TileType characteristic);

    void cellEvent();
};


#endif //UNTITLED2_CELL_H
