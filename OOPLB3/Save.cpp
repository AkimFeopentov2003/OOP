//
// Created by akimfeopentov on 11.12.22.
//

#include "Save.h"

Save::Save(Field &field, std::string st) {
    std::string s;
    s.reserve(1000);
    for (int i = 0; i < 10; i++)
        positions.push_back(s);
    file.open(st, std::ios::out);
    positions[0] = std::to_string(field.get_amountCellsX()) + ' ' + std::to_string(field.get_amountCellsY()) + ' ';
    positions[1] = std::to_string(field.getPlayerPosX()) + ' ' + std::to_string(field.getPlayerPosY()) + ' ';
    positions[2] = std::to_string(field.getPlayer()->getHp()) + ' ';
    for (int i = 0; i < field.get_amountCellsY(); i++)
        for (int j = 0; j < field.get_amountCellsX(); j++) {
            TileType type = field.get_map()[i][j].get_characteristic();
            switch (type) {
                case STONE:
                    positions[3] += std::to_string(i) + ' ' + std::to_string(j) + ' ';
                    break;
                case TELEPORT:
                    positions[4] += std::to_string(i) + ' ' + std::to_string(j) + ' ' +
                                    std::to_string(field.get_map()[i][j].getTransformY()) + ' ' +
                                    std::to_string(field.get_map()[i][j].getTransformX()) + ' ';
                    break;
                case TRAP:
                    positions[5] += std::to_string(i) + ' ' + std::to_string(j) + ' ';
                    break;
                case HP_INC:
                    positions[6] += std::to_string(i) + ' ' + std::to_string(j) + ' ';
                    break;
                case HP_DEC:
                    positions[7] += std::to_string(i) + ' ' + std::to_string(j) + ' ';
                    break;
                case FINISH:
                    positions[8] += std::to_string(i) + ' ' + std::to_string(j) + ' ';
                    break;
                case CRASH:
                    positions[9] += std::to_string(i) + ' ' + std::to_string(j) + ' ' +
                                    std::to_string(field.get_map()[i][j].getTransformY()) + ' ' +
                                    std::to_string(field.get_map()[i][j].getTransformX()) + ' ';
                    break;
            }
        }
    for (int i = 0; i < 10; i++)
        if(i!=9)
            file << positions[i] + "\n";
        else
            file <<positions[i];
    file.close();
}
Save::~Save() {
    file.close();
}