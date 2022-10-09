//
// Created by akimfeopentov on 18.09.22.
//

#include "Controller.h"

Controller::Controller(CommandReader &cur,Field &field) {
    action(cur,field);
}

void Controller::action(CommandReader &cur,Field &field) {
    char order=cur.getCommand();
    if(order=='w'){
        int position= field.getPlayerPosY();
        if(position==0){
            position=field.get_amountCellsY();
        }
        if(field.get_map()[--position][field.getPlayerPosX()].get_characteristic()==GRASS){
            field.setPlayerPosY(position);
        }
    }
    if(order=='s'){
        int position=field.getPlayerPosY();
        if(position==field.get_amountCellsY()-1)
            position=-1;
        if(field.get_map()[++position][field.getPlayerPosX()].get_characteristic()==GRASS){
            field.setPlayerPosY(position);
        }
    }
    if(order=='d'){
        int position=field.getPlayerPosX();
        if(position==field.get_amountCellsX()-1)
            position=-1;
        if(field.get_map()[field.getPlayerPosY()][++position].get_characteristic()==GRASS){
            field.setPlayerPosX(position);
        }
    }
    if(order=='a'){
        int position=field.getPlayerPosX();
        if(position==0)
            position=field.get_amountCellsX();
        if(field.get_map()[field.getPlayerPosY()][--position].get_characteristic()==GRASS){
            field.setPlayerPosX(position);
        }
    }
}