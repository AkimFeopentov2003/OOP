//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_RULESCREATESTONE_H
#define UNTITLED2_RULESCREATESTONE_H
#include "../MapGenerator.h"
template<int x, int y, int ... next>
class RulesCreateStone: public Observable{
public:
    void fill(Field &field) {
        field.get_map()[x][y] = STONE;
        if constexpr (sizeof...(next) > 0)
        {
            RulesCreateStone<next...> rul;
            rul.fill(field);
        }
    }
};
#endif //UNTITLED2_RULESCREATESTONE_H
