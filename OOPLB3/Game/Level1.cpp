//
// Created by akimfeopentov on 18.09.22.
//

#include "Level1.h"
#include "../Log/LogConfigurator.h"
#include "../Unpacker.h"
#include "RecoveryField.h"

void Level1::start() {
    auto logConfigurator = LogConfigurator(this);
    logConfigurator.configure();
    notify(Message(LogType::GameState, "Game start"));
    const int amountCellX = 10;
    const int amountCellY = 7;
    Unpacker unpacker("Level_1_Save.txt");
    Field field;
    char cur = '0';
    if (unpacker.get_map(map)) {
        RecoveryField rf;
        rf.copySubscriptions(this);
        if (rf.GetField(field, map,"Level_1_Save.txt")) {
            std::cout << "Если хотите продолжить игру с момента последнего сохранения нажмите 1, иначе 0 \n";
            std::cin >> cur;
            while (cur < '0' || cur > '1') {
                std::cout << "Ошибка ввода, повторите ввод \n";
                std::cin >> cur;
            }
        }
        else
            notify(Message(LogType::GameState,"Error FileSave"));
    }
    if(cur=='0'){
        MapGenerator<FieldCreateRule<amountCellX, amountCellY>,
                RulesCreateStone<1, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 2, 8, 3, 0, 3, 1, 3, 2, 3, 4,
                        3, 5, 3, 6, 3, 8, 4, 8, 4, 9, 5, 9, 5, 4, 6, 0, 6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 6, 6, 6, 7, 6, 8, 6, 9>,
                RulesCreateTrap<2, 0, 4, 2, 4, 4>,
                RulesCreateTeleport<1, 9, 0, 0>,
                RulesCreatePassage<4, 7, 3, 8, 5, 1, 5, 4>,
                RulesCreateDecHP<0, 1, 1, 0, 1, 1, 2, 1, 2, 2, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 3, 3, 3, 7, 4, 3, 5,
                        2, 5, 3, 5, 6, 5, 7, 5, 8>,
                RulesCreateIncHP<4, 0>,
                RulesCreateHP<100>,
                RulesCreateFinish<2, 9>> mg;
        mg.copySubscriptions(this);
        field = mg.generate();
    }
    gameCurrent(field);
}

void Level1::gameCurrent(Field &field) {
    CommandReader curRead;
    curRead.copySubscriptions(this);
    curRead.setMap();
    Controller Control(curRead, field, "Level_1_Save.txt");
    Control.copySubscriptions(this);
    FieldView painting = FieldView(field);
    painting.Field_write(field);
    while (curRead.getCommand() != CommandType::ESC) {
        curRead.read();
        Control.action(curRead, field);
        std::system("clear");
        painting.Field_write(field);
        if (field.getState() == LOSS) {
            std::cout << "YOU LOSS!\n";
            notify(Message(LogType::GameState, "Game end"));
            break;
        }
        if (field.getState() == WIN) {
            std::cout << "YOU WON!\n";
            notify(Message(LogType::GameState, "Game end"));
            break;
        }
    }
}

Level1::~Level1() {
    map.clear();
}