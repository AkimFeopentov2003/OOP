//
// Created by akimfeopentov on 17.10.22.
//
#include "Level2.h"
#include "../Unpacker.h"
#include "RecoveryField.h"

void Level2::start() {
    auto logConfigurator = LogConfigurator(this);
    logConfigurator.configure();
    notify(Message(LogType::GameState, "Game start"));
    const int amountCellX = 17;
    const int amountCellY = 12;
    Unpacker unpacker("Level_2_Save.txt");
    Field field;
    char cur = '0';
    if (unpacker.get_map(map)) {
        RecoveryField rf;
        rf.copySubscriptions(this);
        if (rf.GetField(field, map, "Level_2_Save.txt")) {
            std::cout << "Если хотите продолжить игру с момента последнего сохранения нажмите 1, иначе 0 \n";
            std::cin >> cur;
            while (cur < '0' || cur > '1') {
                std::cout << "Ошибка ввода, повторите ввод \n";
                std::cin >> cur;
            }
        } else
            notify(Message(LogType::GameState, "Error FileSave"));
    }
    if (cur == '0') {
        MapGenerator<FieldCreateRule<amountCellX, amountCellY>,
                RulesCreateStone<0, 1, 1, 1, 1, 0, 0, 15, 1, 15, 2, 15, 2, 16, 10, 0, 10, 1, 11, 1, 11, 15, 10, 15, 10, 16>,
                RulesCreatePassage<11, 16, 0, 1>,
                RulesCreateDecHP<0, 16>,
                RulesCreateFinish<7, 7>> mg;
        mg.copySubscriptions(this);
        field = mg.generate();
    }

    gameCurrent(field);
}


void Level2::gameCurrent(Field &field) {
    CommandReader curRead;
    curRead.copySubscriptions(this);
    curRead.setMap();
    Controller Control(curRead, field, "Level_2_Save.txt");
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

Level2::~Level2() {
    map.clear();
}