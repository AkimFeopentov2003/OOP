//
// Created by akimfeopentov on 14.10.22.
//

#include "EventStateLoss.h"

void EventStateLoss::eventCell(Field &field) {
    if(field.getPlayer()->getHp()==0)
        field.setState(LOSS);
    notify(Message(LogType::ObjectState,"actuation EventStateLoss"));
}
EventStateLoss::~EventStateLoss() {}