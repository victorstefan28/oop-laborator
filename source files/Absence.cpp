//
// Created by vik on 4/24/2023.
//

#include "../headers/headers.h"

Absence::Absence() : Mark()
{
    tip = "";
}

Absence::Absence(std::string tip_, std::string discipline_, std::string date_) : Mark(date_, discipline_)
{
    tip = tip_;
}
Absence::Absence(std::string tip_, std::string discipline_) : Mark(discipline_)
{
    tip = tip_;
}
