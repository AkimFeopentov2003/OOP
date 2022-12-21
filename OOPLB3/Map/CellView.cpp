//
// Created by akimfeopentov on 18.09.22.
//

#include "CellView.h"

void CellView::write_Cell(Cell &current) {
    switch (current.get_characteristic()) {
        case GRASS:
            std::cout << '_';
            break;
        case STONE:
            std::cout << '#';
            break;
        case TRAP:
            std::cout << '?';
            break;
        case HP_DEC:
            std::cout << '-';
            break;
        case HP_INC:
            std::cout << '+';
            break;
        case TELEPORT:
            std::cout << 'T';
            break;
        case CRASH:
            std::cout << 'C';
            break;
        case FINISH:
            std::cout << 'F';
            break;
    }
}