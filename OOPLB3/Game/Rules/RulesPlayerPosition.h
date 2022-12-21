//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESPLAYERPOSITION_H
#define UNTITLED2_RULESPLAYERPOSITION_H
#include "../MapGenerator.h"
template <int x, int y>
class PlayerPositionRule: public Observable{
public:
    void fill(Field &field) {
        field.setPlayerPosX(x);
        field.setPlayerPosY(y);
    }
};
#endif //UNTITLED2_RULESPLAYERPOSITION_H
