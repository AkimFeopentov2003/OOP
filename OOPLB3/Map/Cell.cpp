//
// Created by akimfeopentov on 15.09.22.
//

#include "Cell.h"

Cell::Cell(TileType characteristic) : characteristic(characteristic), m_event(nullptr) { }

void Cell::setCharacteristic(TileType characteristic) {
    Cell::characteristic = characteristic;
}

void Cell::triggerEvent(Field &field) {
    if (m_event != nullptr) {
        m_event->eventCell(field);
    }
}

void Cell::setEvent(Event *event) {
    m_event = event;
}

void Cell::setTransformX(int transformX) {
    this->transformX=transformX;
}

void Cell::setTransformY(int transformY) {
    this->transformY=transformY;
}
int Cell::getTransformX() {
    return transformX;
}

int Cell::getTransformY() {
    return  transformY;
}
Cell::Cell(const Cell &other) {
    this->transformY=other.transformY;
    this->transformX=other.transformX;
    this->m_event=other.m_event;
    this->characteristic=other.characteristic;
}
Cell::Cell(Cell &&other) {
    this->transformY=other.transformY;
    this->transformX=other.transformX;
    this->m_event=other.m_event;
    this->characteristic=other.characteristic;
}

Cell &Cell::operator=(Cell &&other) {
    this->transformY=other.transformY;
    this->transformX=other.transformX;
    this->m_event=other.m_event;
    this->characteristic=other.characteristic;
}
Cell &Cell::operator=(const Cell &other) {
    this->transformY=other.transformY;
    this->transformX=other.transformX;
    this->m_event=other.m_event;
    this->characteristic=other.characteristic;
    return *this;
}
