//
// Created by akimfeopentov on 18.09.22.
//

#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H


class Player {
    int hp;
    int armor;
    int ammo;
public:
    Player(int hp=100, int armor=100, int ammo=10);
    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        Player::hp = hp;
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        this->armor = armor;
    }

    int getAmmo() const {
        return ammo;
    }

    void setAmmo(int ammo) {
        this->ammo = ammo;
    }
};


#endif //UNTITLED2_PLAYER_H
