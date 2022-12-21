//
// Created by akimfeopentov on 14.10.22.
//

#include "EventPlayerHPDec.h"


void EventPlayerHPDec::eventCell(Field &field) {
    const int DecHp=10;
    int hp = field.getPlayer()->getHp();
    if (hp >= DecHp) {
        hp -= DecHp;
    }
    else{
        hp = 0;
    }

    field.getPlayer()->setHp(hp);
    notify(Message(LogType::ObjectState,"actuation EventPlayerHPDec"));
    if(hp==0){
        field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(new EventStateLoss);
        field.triggerCellEvent();
    }
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(nullptr);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()]=GRASS;
}
EventPlayerHPDec::~EventPlayerHPDec() {}
