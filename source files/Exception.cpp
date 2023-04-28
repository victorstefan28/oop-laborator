//
// Created by vik on 4/27/2023.
//

#include "../headers/headers.h"

input_exception::input_exception(std::string msg_) : msg(msg_+'\n') {};
input_exception::input_exception() : msg("Input Exception - No message\n") {};
const char* input_exception::what() const throw()
{

    return msg.c_str();
}

invalid_arg::invalid_arg(std::string msg_) : msg(msg_+'\n') {};
invalid_arg::invalid_arg() : msg("Argument passed is invalid\n") {};
const char* invalid_arg::what() const throw()
{

    return msg.c_str();
}
