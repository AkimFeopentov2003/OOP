//
// Created by akimfeopentov on 18.09.22.
//
#include "Map/Field.h"
#include "Map/FieldView.h"
#include "Player/Player.h"
#include "Read/CommandReader.h"
#include "Log/Observable.h"

#ifndef UNTITLED2_CONTROLER_H
#define UNTITLED2_CONTROLER_H

#include "Log/FileLogger.h"
#include "Read/CommandFile.h"
#include <map>
#include "Read/CommandType.h"
#include "functional"
#include <string>

class Controller : public Observable {
    std::map<CommandType,std::function<void (int&,int&,Field&)>> map;
    std::string st;
public:
    Controller(CommandReader &cur, Field &field, std::string st);

    void action(CommandReader &cur, Field &field);

    void SaveFile(Field &field);

    ~Controller();

};


#endif //UNTITLED2_CONTROLER_H
