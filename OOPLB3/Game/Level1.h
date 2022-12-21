//
// Created by akimfeopentov on 18.09.22.
//

#ifndef UNTITLED2_LEVEL1_H
#define UNTITLED2_LEVEL1_H

#include <iostream>
#include "Level.h"
#include "../Map/FieldView.h"
#include "../Map/Field.h"
#include "../Read/CommandReader.h"
#include "../Controller.h"
#include "../Events/EventMapTrap.h"
#include "../Events/EventPlayerTeleport.h"
#include "../Events/EventMapPassage.h"
#include "../Events/EventStateWin.h"
#include "../Events/EventPlayerHPDec.h"
#include "../Events/EventPlayerHPInc.h"
#include "MapGenerator.h"
#include "Rules/CreateField.h"
#include "Rules/RulesCreateCrash.h"
#include "Rules/RulesCreateDecHP.h"
#include "Rules/RulesCreateStone.h"
#include "Rules/RulesCreateTeleport.h"
#include "Rules/RulesCreateTrap.h"
#include "Rules/RuleseCreateIncHP.h"
#include "Rules/RulesCreateFinish.h"
#include "Rules/RulesCreateHP.h"

class Level1: public Level {
    std::map<int,std::vector<int>> map;
public:
    void start();
    void gameCurrent(Field &field);
    ~Level1();
};


#endif //UNTITLED2_LEVEL1_H
