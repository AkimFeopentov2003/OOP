//
// Created by akimfeopentov on 18.09.22.
//

#include "Game.h"


void Game::start() {
    Field field;
    std::cout << "START\n";
    int curwrite;
    std::cout<<"Если хотите ввести размер поля введите 1 иначе 2\n";
    std::cin>>curwrite;
    while(curwrite!=1 && curwrite!=2){
        std::cout<<"Ошибка ввода, повторите ввод\n";
        std::cin>>curwrite;
    }
    int amountCellX,amountCellY;
    if(curwrite==1){
        std::cout<<"Введите количество клеток по вертикали и горизонтали соответственно\n";
        std::cout<<"Минимальный размер 5, максимальный 30\n";
        std::cin>>amountCellY>>amountCellX;
        while(amountCellY<5 || amountCellY>30){
             std::cout<<"Вы не верно ввели количество клеток по вертикали, пожалуйста повторите ввод одной клетки по вертикали\n";
             std::cin>>amountCellY;
        }
        while (amountCellX<5 || amountCellX>30){
            std::cout<<"Вы не верно ввели количество клеток по горизонтали, пожалуйста повторите ввод одной клетки по горизонтали\n";
            std::cin>>amountCellX;
        }
        Field field=Field(amountCellX,amountCellY);
    }
    else{
        Field field=Field();
    }
    for(int i=1;i<field.get_amountCellsY()-1;i++)
        for(int j=0;j<field.get_amountCellsX();j++)
            if(j%2==1)
                field.get_map()[i][j].setCharacteristic(STONE);
    gameCurrent(field);
}

void Game::gameCurrent(Field &field) {
    CommandReader curRead;
    while (curRead.getCommand() != 'l') {
       //2
       // std::system("clear") ;
        FieldView painting = FieldView(field);
        curRead.read();
        Controller Control = Controller(curRead, field);

    }
}