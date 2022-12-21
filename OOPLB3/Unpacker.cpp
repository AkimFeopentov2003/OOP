//
// Created by akimfeopentov on 11.12.22.
//

#include "Unpacker.h"
#include "Exception/Exception.h"
#include <iostream>

Unpacker::Unpacker(std::string st) {
    file.open(st, std::ios::in);
    this->st=st;
}

bool Unpacker::get_map(std::map<int, std::vector<int>> &map) {
    if (!file.fail()) {
        int count=0;
        while (!file.eof()) {
            std::string str;
            std::getline(file, str);
            if(!ReaderSave(str,count,map)){
                return false;
            };
            count++;
        }
        if(map.size()==10)
            return true;
        else
            return false;
    } else
        return false;
}

bool Unpacker::ReaderSave(std::string str, int count,std::map<int, std::vector<int>> &map) {
    if(str.size()==0){
        map[count].push_back(-1);
    }
    while (str.size()!=0){
        int i=0;
        if(str.find(' ')!=std::string::npos){
            auto it = str.find(' ');
            i=(stoi(str.substr(0,it)));
            str.erase(0,it+1);
        }
        else{
            i=(stoi(str));
            str.clear();
        }
        if(i<0) {
            try {
                throw Exception(
                        "Received a negative number in the " + st + " on the line number " + std::to_string(count+1));
            }
            catch(Exception & es) {
                std::cout<<es.what()<<std::endl;
                return false;
            }
        }
        map[count].push_back(i);
    }
    return true;
}
