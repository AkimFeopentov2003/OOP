//
// Created by akimfeopentov on 12.10.22.
//

#include "EventPlayerHPInc.h"
#include <iostream>

void EventPlayerHPInc::eventCell(Field &field) {
    const int IncHp=10;
    int hp = field.getPlayer()->getHp();
    if (hp <= 100-IncHp) {
        hp += IncHp;
    } else
        hp = 100;
    field.getPlayer()->setHp(hp);
    notify(Message(LogType::ObjectState,"actuation EventPlayerHPInc"));
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(nullptr);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()] = GRASS;
}
EventPlayerHPInc::~EventPlayerHPInc() {}