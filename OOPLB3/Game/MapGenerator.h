//
// Created by akimfeopentov on 29.11.22.
//

#ifndef UNTITLED2_MAPGENERATOR_H
#define UNTITLED2_MAPGENERATOR_H
#include "../Map/Field.h"
#include "../Log/Observable.h"

template <typename ... Rules>
class MapGenerator: public Observable{
    Field field;
    template <typename Rule, typename ... RestRules>
    void modifyField() {
        Rule curR;
        curR.copySubscriptions(this);
        curR.fill(field);
        if constexpr (sizeof...(RestRules) > 0) {
            modifyField<RestRules...>();
        }
    }
public:
    MapGenerator(){}
    Field generate() {
        modifyField<Rules...>();
        return field;
    }

};


#endif //UNTITLED2_MAPGENERATOR_H
