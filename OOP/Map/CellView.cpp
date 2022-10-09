//
// Created by akimfeopentov on 18.09.22.
//

#include "CellView.h"

void CellView::write_Cell(Cell &current) {
    if(current.get_characteristic()==GRASS){
        std::cout<<'_';
    }
    if(current.get_characteristic()==STONE){
        std::cout<<'#';
    }
}