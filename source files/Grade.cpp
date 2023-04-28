//
// Created by vik on 4/10/2023.
//

#include "../headers/Grade.h"

int Grade::GetValue() const
{
    return value;
}
void Grade::SetValue(int val)
{
    value = val;
}
Grade::Grade(int value_, std::string discipline_, std::string date_) : Mark(date_, discipline_)
{
    SetValue(value_);
}
Grade::Grade(int value_, std::string discipline_) : Mark(discipline_)
{
    SetValue(value_);
}

void Grade::afiseaza(std::ostream& os) const {
    std::cout<<"Nota "<<GetValue()<<" la materia "<<GetDiscipline()<<'\n';
}

bool Grade::operator==(const Grade &rhs) const {
    return this->value == rhs.value;
}
bool Grade::operator!=(const Grade &rhs) const
{
    return !(*this == rhs);
}
std::ostream& operator<<(std::ostream& os, const Grade &rhs)
{
    rhs.afiseaza(os);
    return os;
}
Grade& Grade::operator=(const Grade &rhs)
{
    if(this == &rhs)
        return *this;
    Mark::operator=(rhs);
    value = rhs.GetValue();
    return *this;
}