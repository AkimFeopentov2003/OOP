//
// Created by akimfeopentov on 11.12.22.
//

#ifndef UNTITLED2_RECOVERYFIELD_H
#define UNTITLED2_RECOVERYFIELD_H
#include <map>
#include <vector>
#include "../Map/Field.h"
#include "../Log/Observable.h"
#include "../Events/EventMapTrap.h"
#include "../Events/EventPlayerTeleport.h"
#include "../Events/EventMapPassage.h"
#include "../Events/EventStateWin.h"
#include "../Events/EventPlayerHPDec.h"
#include "../Events/EventPlayerHPInc.h"

class RecoveryField: public Observable{
public:
    RecoveryField();
    bool GetField(Field &field,std::map<int,std::vector<int>> &map,std::string st);
};


#endif //UNTITLED2_RECOVERYFIELD_H
