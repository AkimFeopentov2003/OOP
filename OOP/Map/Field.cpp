//
// Created by akimfeopentov on 15.09.22.
//

#include "Field.h"

Field::Field(int amountCellsX, int amountCellsY) {
    this->amountCellsX = amountCellsX;
    this->amountCellsY = amountCellsY;
    this->map=new Cell *[this->get_amountCellsY()];
    for (int i = 0; i < this->get_amountCellsY(); i++) {
        map[i] = new Cell[this->get_amountCellsX()];
    }
    this->playerPosX = 0;
    this->playerPosY = 0;
}

Field::Field(const Field &other): amountCellsX(other.amountCellsX),amountCellsY(other.amountCellsY) {
    this->amountCellsX = other.amountCellsX;
    this->amountCellsY = other.amountCellsY;
    this->playerPosX = other.playerPosX;
    this->playerPosY = other.playerPosY;
    this->map = new Cell *[other.playerPosY];
    for (int i = 0; i < other.amountCellsY; i++) {
        this->map[i] = new Cell[other.amountCellsX];
    }
    for(int i=0;i<other.amountCellsY;i++)
        for (int j = 0; j < other.amountCellsX; j++)
            this->map[i][j] = other.map[i][j];

}
Field::Field(Field &&other): amountCellsX(other.amountCellsX),amountCellsY(other.amountCellsY) {
    this->amountCellsX = other.amountCellsX;
    this->amountCellsY = other.amountCellsY;
    this->playerPosX = other.amountCellsX;
    this->playerPosY = other.playerPosY;
    this->map = new Cell *[other.playerPosY];
    for (int i = 0; i < other.amountCellsY; i++) {
        this->map[i] = new Cell[other.amountCellsX];
    }
    for(int i=0;i<other.amountCellsY;i++)
        for (int j = 0; j < other.amountCellsX; j++)
            this->map[i][j] = other.map[i][j];
    other.map= nullptr;
    other.amountCellsX= 0;
    other.amountCellsY=0;
    other.playerPosY=0;
    other.playerPosX=0;
}

Field &Field::operator=(const Field &other) {
    this->amountCellsX = other.amountCellsX;
    this->amountCellsY = other.amountCellsY;
    this->playerPosY = other.playerPosY;
    this->playerPosX = other.playerPosX;
    if (this->map != nullptr) {
        delete[] this->map;
    }
    this->map = new Cell *[other.playerPosY];
    for (int i = 0; i < other.amountCellsY; i++) {
        this->map[i] = new Cell[other.amountCellsX];
    }
    for(int i=0;i<other.amountCellsY;i++)
        for (int j = 0; j < other.amountCellsX; j++)
            this->map[i][j] = other.map[i][j];
    return *this;
}

Field &Field::operator=(Field &&other) {
    this->amountCellsX = other.amountCellsX;
    this->amountCellsY = other.amountCellsY;
    this->playerPosY = other.playerPosY;
    this->playerPosX = other.playerPosX;
    if (this->map != nullptr) {
        delete[] this->map;
    }
    this->map = new Cell *[other.playerPosY];
    for (int i = 0; i < other.amountCellsY; i++) {
        this->map[i] = new Cell[other.amountCellsX];
        for (int j = 0; j < other.amountCellsX; j++)
            this->map[i][j] = other.map[i][j];
    }
    other.map= nullptr;
    other.amountCellsX= 0;
    other.amountCellsY=0;
    other.playerPosY=0;
    other.playerPosX=0;
    return *this;
}

int Field::getPlayerPosX() const {
    return playerPosX;
}

void Field::setPlayerPosX(int playerPosX) {
    Field::playerPosX = playerPosX;
}

int Field::getPlayerPosY() const {
    return playerPosY;
}

void Field::setPlayerPosY(int playerPosY) {
    Field::playerPosY = playerPosY;
}

Field::~Field() {
    delete[] map;
}
