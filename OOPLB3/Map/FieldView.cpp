//
// Created by akimfeopentov on 18.09.22.
//

#include "FieldView.h"

void FieldView::Field_write(Field &field) {
    CellView view;
    std::cout << "hp:" << field.getPlayer()->getHp() << "  " << "armor:" << field.getPlayer()->getArmor() << "\n\n";
    for (int i = 0; i < field.get_amountCellsY(); i++) {
        for (int j = 0; j < field.get_amountCellsX(); j++) {
            if (i == field.getPlayerPosY() && j == field.getPlayerPosX())
                std::cout << 'P';
            else {
                view.write_Cell(field.get_map()[i][j]);
            }
        }
        std::cout << "\n";
    }
}