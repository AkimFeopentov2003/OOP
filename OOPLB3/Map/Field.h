//
// Created by akimfeopentov on 15.09.22.
//


#ifndef UNTITLED2_FIELD_H
#define UNTITLED2_FIELD_H
class Field;
enum GameState {
    WIN, LOSS, PLAYING
};
#include "Cell.h"
#include "../Player/Player.h"

class Field {
    int playerPosX;
    int playerPosY;
    int amountCellsX;
    int amountCellsY;
    Cell **map;
    Player *player=(new Player);
    GameState state;
public:
    int getPlayerPosX() const;

    GameState getState() const;
    void setState(GameState newState);

    void setPlayerPosX(int playerPosX = 0);

    int getPlayerPosY() const;

    void setPlayerPosY(int playerPosY = 0);

    void setCell(int x, int y, Cell newCell);

    explicit Field(int amountCellsX = 10, int amountCellsY = 10);

    Field(const Field &other);

    Field &operator=(const Field &other);

    Field(Field &&other);
    Field &operator=(Field &&other);

    void triggerCellEvent();

    int get_amountCellsX() const {
        return amountCellsX;
    }

    int get_amountCellsY() const {
        return amountCellsY;
    }

    Cell **get_map() {
        return map;
    }
    Player *getPlayer();

    ~Field();
};


#endif //UNTITLED2_FIELD_H
