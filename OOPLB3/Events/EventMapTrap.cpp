//
// Created by akimfeopentov on 14.10.22.
//

#include "EventMapTrap.h"

void EventMapTrap::eventCell(Field &field) {
    int x = field.getPlayerPosX();
    int y = field.getPlayerPosY();
    field.setCell(x + 2, y, Cell(STONE));
    field.setCell(x - 1, y, Cell(STONE));
    field.setCell(x, y + 1, Cell(STONE));
    field.setCell(x, y - 1, Cell(STONE));
    field.setCell(x + 1, y + 1, Cell(STONE));
    field.setCell(x + 1, y - 1, Cell(STONE));
    notify(Message(LogType::ObjectState,"actuation EventMapTrap"));
    Event *ev = new EventPlayerHPTrap;
    ev->copySubscriptions(this);
    field.get_map()[y][x]=HP_DEC;
    field.get_map()[y][((x + 1) % field.get_amountCellsX() + field.get_amountCellsX()) %
                       field.get_amountCellsX()]=HP_DEC;
    field.get_map()[y][x].setEvent(ev);
    field.get_map()[y][((x + 1) % field.get_amountCellsX() + field.get_amountCellsX()) %
                       field.get_amountCellsX()].setEvent(ev);
}
EventMapTrap::~EventMapTrap() {}
/* P_##_
 * _#P_#
 * __##_
 */