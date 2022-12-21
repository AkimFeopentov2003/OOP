//
// Created by akimfeopentov on 11.12.22.
//

#include "RecoveryField.h"
#include "../Exception/Exception.h"
#include <iostream>

RecoveryField::RecoveryField() {
}

bool RecoveryField::GetField(Field &field, std::map<int, std::vector<int>> &map, std::string st) {
    if (map[0][0] != -1) {
        if (map[0].size() == 2) {
            if (map[0][0] < 50 && map[0][1] < 50)
                field = Field(map[0][0], map[0][1]);
            else if (map[0][0] >= 50) {
                try {
                    throw Exception("Error in file " + st + " in the line 0, first number must be less than 50");
                }
                catch (Exception &ev) {
                    std::cout << ev.what() << std::endl;
                    return false;
                }
            } else
                try {
                    throw Exception("Error in file " + st + " in the line 0, second number must be less than 50");
                }
                catch (Exception &ev) {
                    std::cout << ev.what() << std::endl;
                    return false;
                }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 0, size must be 2 ");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[1][0] != -1) {
        if (map[1].size() == 2) {
            if (map[1][0] < field.get_amountCellsX() && map[1][1] < field.get_amountCellsY()) {
                field.setPlayerPosX(map[1][0]);
                field.setPlayerPosY(map[1][1]);
            } else if (map[1][0] >= field.get_amountCellsX()) {
                try {
                    throw Exception("Error in file " + st + " in the line 1, first number must be less than " +
                                    std::to_string(field.get_amountCellsX()));
                }
                catch (Exception &ev) {
                    std::cout << ev.what() << std::endl;
                    return false;
                }
            } else
                try {
                    throw Exception("Error in file " + st + " in the line 1, second number must be less than " +
                                    std::to_string(field.get_amountCellsY()));
                }
                catch (Exception &ev) {
                    std::cout << ev.what() << std::endl;
                    return false;
                }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 1, size must be 2 ");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[2][0] != -1) {
        if (map[2].size() == 1) {
            if (map[2][0] <= 100) {
                field.getPlayer()->setHp(map[2][0]);
            } else {
                try {
                    throw Exception("Error in file " + st + " in the line 2,number must be less than 101");
                }
                catch (Exception &ev) {
                    std::cout << ev.what() << std::endl;
                    return false;
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 1, size must be 1 ");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[3][0] != -1) {
        if (map[3].size() % 2 == 0 || map[3].size() > 1) {
            for (int i = 0; i < map[3].size() - 1; i += 2)
                if (map[3][i] < field.get_amountCellsY() && map[3][i + 1] < field.get_amountCellsX()) {
                    field.get_map()[map[3][i]][map[3][i + 1]] = STONE;
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 3, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 3, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[4][0] != -1) {
        if (map[4].size() % 4 == 0 || map[4].size() > 3) {
            for (int i = 0; i < map[4].size() - 3; i += 4) {
                if (map[3][i] < field.get_amountCellsY() && map[3][i + 1] < field.get_amountCellsX() &&
                    map[3][i + 2] < field.get_amountCellsY() && map[3][i + 3] < field.get_amountCellsX()) {
                    Event *ev = new EventPlayerTeleport(map[4][i + 2], map[4][i + 3]);
                    ev->copySubscriptions(this);
                    field.get_map()[map[4][i]][map[4][i + 1]] = TELEPORT;
                    field.get_map()[map[4][i]][map[4][i + 1]].setTransformY(map[4][i + 2]);
                    field.get_map()[map[4][i]][map[4][i + 1]].setTransformX(map[4][i + 3]);
                    field.get_map()[map[4][i]][map[4][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 4, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 4, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[5][0] != -1) {
        if (map[5].size() % 2 == 0 || map[5].size() > 1) {
            for (int i = 0;i < map[5].size()- 1; i += 2) {
                if (map[5][i] < field.get_amountCellsY() && map[5][i + 1] < field.get_amountCellsX()) {
                    Event *ev = new EventMapTrap();
                    ev->copySubscriptions(this);
                    field.get_map()[map[5][i]][map[5][i + 1]] = TRAP;
                    field.get_map()[map[5][i]][map[5][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 5, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 5, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[6][0] != -1) {
        if (map[6].size()% 2 == 0 || map[6].size()> 1) {
            for (int i = 0;i < map[6].size()- 1; i += 2) {
                if (map[6][i] < field.get_amountCellsY() && map[6][i + 1] < field.get_amountCellsX()) {
                    Event *ev = new EventPlayerHPInc();
                    ev->copySubscriptions(this);
                    field.get_map()[map[6][i]][map[6][i + 1]] = HP_INC;
                    field.get_map()[map[6][i]][map[6][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 6, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 6, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[7][0] != -1) {
        if (map[7].size()% 2 == 0 || map[7].size()> 1) {
            for (int i = 0;i < map[7].size()- 1; i += 2) {
                if (map[7][i] < field.get_amountCellsY() && map[7][i + 1] < field.get_amountCellsX()) {
                    Event *ev = new EventPlayerHPDec();
                    ev->copySubscriptions(this);
                    field.get_map()[map[7][i]][map[7][i + 1]] = HP_DEC;
                    field.get_map()[map[7][i]][map[7][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 7, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 7, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[8][0] != -1) {
        if (map[8].size()% 2 == 0 || map[3].size()> 1) {
            for (int i = 0;i < map[8].size()- 1; i += 2) {
                if (map[8][i] < field.get_amountCellsY() && map[8][i + 1] < field.get_amountCellsX()) {
                    Event *ev = new EventStateWin();
                    ev->copySubscriptions(this);
                    field.get_map()[map[8][i]][map[8][i + 1]] = FINISH;
                    field.get_map()[map[8][i]][map[8][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 8, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 8, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    if (map[9][0] != -1) {
        if (map[9].size()% 4 == 0 && map[9].size()>= 4) {
            for (int i = 0;i < map[9].size()- 3; i += 4) {
                if (map[9][i] < field.get_amountCellsY() && map[9][i + 1] < field.get_amountCellsX() &&
                    map[9][i + 2] < field.get_amountCellsY() && map[9][i + 3] < field.get_amountCellsX()) {
                    Event *ev = new EventMapPassage(map[9][i + 2], map[9][i + 3]);
                    ev->copySubscriptions(this);
                    field.get_map()[map[9][i]][map[9][i + 1]] = CRASH;
                    field.get_map()[map[9][i]][map[9][i + 1]].setTransformY(map[9][i + 2]);
                    field.get_map()[map[9][i]][map[9][i + 1]].setTransformX(map[9][i + 3]);
                    field.get_map()[map[9][i]][map[9][i + 1]].setEvent(ev);
                } else {
                    try {
                        throw Exception("Error in file " + st + " in the line 9, field oversize");
                    }
                    catch (Exception &ev) {
                        std::cout << ev.what() << std::endl;
                        return false;
                    }
                }
            }
        } else
            try {
                throw Exception("Error in file " + st + " in the line 9, missing elements");
            }
            catch (Exception &ev) {
                std::cout << ev.what() << std::endl;
                return false;
            }
    }
    return true;
}