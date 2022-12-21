//
// Created by akimfeopentov on 11.12.22.
//

#ifndef UNTITLED2_SAVE_H
#define UNTITLED2_SAVE_H
#include <fstream>
#include "Map/Field.h"
#include <string>
#include <vector>

class Save {
    std::fstream file;
    std::vector<std::string> positions ;
public:
    Save(Field &field,std::string st);
    ~Save();
};


#endif //UNTITLED2_SAVE_H
