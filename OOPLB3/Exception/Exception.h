//
// Created by akimfeopentov on 12.12.22.
//

#ifndef UNTITLED2_EXCEPTION_H
#define UNTITLED2_EXCEPTION_H
#include <exception>
#include <string>

class Exception {
public:
    Exception(std::string index) noexcept;
    const char* what() const noexcept;
private:
    std::string errorIndex;
};


#endif //UNTITLED2_EXCEPTION_H
