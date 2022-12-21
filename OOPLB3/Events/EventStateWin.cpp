//
// Created by akimfeopentov on 14.10.22.
//

#include "EventStateWin.h"

void EventStateWin::eventCell(Field &field) {
    if(field.getPlayer()->getHp()>0){
        field.setState(WIN);
    }
    notify(Message(LogType::ObjectState,"actuation EventStateWin"));
}
EventStateWin::~EventStateWin() {}