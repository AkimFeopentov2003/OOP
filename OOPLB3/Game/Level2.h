//
// Created by akimfeopentov on 17.10.22.
//

#ifndef UNTITLED2_LEVEL2_H
#define UNTITLED2_LEVEL2_H
#include "iostream"
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
#include "../Log/LogConfigurator.h"
#include "Rules/RulesCreateHP.h"

class Level2: public Level{
    std::map<int,std::vector<int>> map;
public:
    void start();
    void gameCurrent(Field &field);
    ~Level2();
};


#endif //UNTITLED2_LEVEL2_H
