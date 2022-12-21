//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_CREATEFIELD_H
#define UNTITLED2_CREATEFIELD_H
#include "../../Map/Field.h"
template <int x, int y>
class FieldCreateRule: public Observable {
public:
    void fill(Field &field) {
        field = Field(x, y);
    }
};
#endif //UNTITLED2_CREATEFIELD_H
