//
// Created by akimfeopentov on 15.09.22.
//

#include "Cell.h"

void Cell::cellEvent() {
    this->event.eventCell();
}

void Cell::setCharacteristic(TileType characteristic) {
    Cell::characteristic = characteristic;
}
