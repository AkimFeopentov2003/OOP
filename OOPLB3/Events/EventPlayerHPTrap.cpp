//
// Created by akimfeopentov on 16.10.22.
//

#include "EventPlayerHPTrap.h"

void EventPlayerHPTrap::eventCell(Field &field) {
    int hp = field.getPlayer()->getHp();
    if (hp >= 10) {
        hp -= 10;
    } else {
        hp = 0;
    }

    field.getPlayer()->setHp(hp);
    notify(Message(LogType::ObjectState,"actuation EventPlayerHPDec"));
    if (hp == 0) {
        field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(new EventStateLoss);
        field.triggerCellEvent();
    }
}
EventPlayerHPTrap::~EventPlayerHPTrap() {}