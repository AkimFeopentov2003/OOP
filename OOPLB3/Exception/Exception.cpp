//
// Created by akimfeopentov on 12.12.22.
//

#include "Exception.h"
#include <string>
#include <cstring>

Exception::Exception(std::string index) noexcept : errorIndex(index) {}
const char* Exception::what() const noexcept {
    std::string start = "Slon error at ";
    std::string index = errorIndex;
    char *res = new char[start.size() + index.size() + 1];

    strcpy(res, start.c_str());
    strcat(res, index.c_str());

    return res;
}