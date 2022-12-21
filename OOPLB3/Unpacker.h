//
// Created by akimfeopentov on 11.12.22.
//

#ifndef UNTITLED2_UNPACKER_H
#define UNTITLED2_UNPACKER_H
#include <fstream>
#include <string>
#include <vector>
#include <map>

class Unpacker {
    std::fstream file;
    std::string st;
public:
    Unpacker(std::string st);
    bool get_map(std::map<int,std::vector<int>> &map);
    bool ReaderSave(std::string,int count, std::map<int, std::vector<int>> &map);
};


#endif //UNTITLED2_UNPACKER_H
