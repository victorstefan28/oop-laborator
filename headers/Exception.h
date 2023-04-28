//
// Created by vik on 4/27/2023.
//

#ifndef CLION_PROJ_EXCEPTION_H
#define CLION_PROJ_EXCEPTION_H

#include "headers.h"
class input_exception : std::exception {
    std::string msg;
public:
    input_exception(std::string msg_);
    input_exception();
    const char* what() const throw() override;
};

class invalid_arg : std::exception {
    std::string msg;
public:
    invalid_arg(std::string msg_);
    invalid_arg();
    const char* what() const throw() override;
};

#endif //CLION_PROJ_EXCEPTION_H
