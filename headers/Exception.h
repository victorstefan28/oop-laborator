//
// Created by vik on 4/27/2023.
//

#ifndef CLION_PROJ_EXCEPTION_H
#define CLION_PROJ_EXCEPTION_H

#include "headers.h"
class input_exception : std::exception {
    std::string msg;
public:
    explicit input_exception(const std::string& msg_);
    input_exception();
    const char* what() const throw() override;
};

class invalid_arg : std::exception {
    std::string msg;
public:
    explicit invalid_arg(const std::string& msg_);
    invalid_arg();
    const char* what() const throw() override;
};

#endif //CLION_PROJ_EXCEPTION_H
