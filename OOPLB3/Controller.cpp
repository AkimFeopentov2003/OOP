//
// Created by akimfeopentov on 18.09.22.
//

#include "Controller.h"
#include "Log/message.h"
#include "Save.h"

Controller::Controller(CommandReader &cur, Field &field,std::string st) {
    this->st=st;
    map.emplace(CommandType::DOWN, [](int &first, int &second, Field& field) {
        ++first;
    });
    map.emplace(CommandType::UP, [](int &first, int &second,Field& field) {
        --first;
    });
    map.emplace(CommandType::LEFT, [](int &first, int &second,Field& field) {
        --second;
    });
    map.emplace(CommandType::RIGHT, [](int &first, int &second,Field& field) {
        ++second;
    });
    map.emplace(CommandType::ESC, [this](int &first, int &second,Field& field) {
        notify(Message(LogType::GameState, "Game end"));
    });
    map.emplace(CommandType::ERROR, [this](int &first, int &second,Field& field) {
        notify(Message(LogType::CriticalState, "Wrong command"));
    });
    map.emplace(CommandType::PAUSE, [this](int &first, int &second, Field& field) {
        SaveFile(field);
        notify(Message(LogType::GameState, "Preservation\n"));
    });
}

void Controller::action(CommandReader &cur, Field &field) {
    CommandType order = cur.getCommand();
    std::pair<int, int> newPosition;
    newPosition.first = field.getPlayerPosY();
    newPosition.second = field.getPlayerPosX();
    map[order](newPosition.first,newPosition.second,field);
    newPosition.first =
            (newPosition.first % field.get_amountCellsY() + field.get_amountCellsY()) % field.get_amountCellsY();
    newPosition.second =
            (newPosition.second % field.get_amountCellsX() + field.get_amountCellsX()) % field.get_amountCellsX();
    if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() != STONE &&
        (field.getPlayerPosY() != newPosition.first || field.getPlayerPosX() != newPosition.second)) {
        field.setPlayerPosY(newPosition.first);
        field.setPlayerPosX(newPosition.second);
        field.triggerCellEvent();
        notify(Message(LogType::ObjectState,
                       "Player changed position " + std::to_string(field.getPlayerPosY()) + " " +
                       std::to_string(field.getPlayerPosX())));
    } else {
        if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() == STONE)
            notify(Message(LogType::GameState, "player tries to pass through stone!"));
    }
}

void Controller::SaveFile(Field &field) {
    Save save(field,st);
}

Controller::~Controller() {
    map.clear();
}