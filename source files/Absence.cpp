//
// Created by vik on 4/24/2023.
//

#include "../headers/headers.h"

Absence::Absence() : Mark(), tip("")
{

}

Absence::Absence(const std::string& tip_, const std::string& discipline_, const std::string& date_) : Mark(date_, discipline_), tip(tip_)
{

}
Absence::Absence(const std::string& tip_, const std::string& discipline_) : Mark(discipline_), tip(tip_)
{

}
Absence& Absence::operator=(const Absence &rhs)
{
    if(this == &rhs)
        return *this;
    Mark::operator=(rhs);
    tip = rhs.GetTip();
    return *this;
}