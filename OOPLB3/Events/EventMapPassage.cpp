//
// Created by akimfeopentov on 15.10.22.
//

#include "EventMapPassage.h"
EventMapPassage::EventMapPassage(int PosCrashY, int PosCrashX) {
    this->PosCrashX=PosCrashX;
    this->PosCrashY=PosCrashY;
}

void EventMapPassage::eventCell(Field &field) {
    field.get_map()[PosCrashY][PosCrashX]=GRASS;
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(nullptr);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()] = GRASS;
    notify(Message(LogType::ObjectState,"actuation EventMapPassage"));
}
EventMapPassage::~EventMapPassage() {};