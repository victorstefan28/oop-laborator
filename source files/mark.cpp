//
// Created by vik on 4/7/2023.
//

#include "../headers/mark.h"
Mark::Mark() : date(""), discipline("")
{

}
Mark::Mark(const Mark &o)
{
//    value = o.value;

    /*date = new char[strlen(o.date)+1];

    description = new char[strlen(o.description)+1];
    discipline = new char[strlen(o.discipline)+1];

    strcpy(description, o.description);
    strcpy(date, o.date);
    strcpy(discipline, o.discipline);*/
    SetDate(o.GetDate());
    SetDiscipline( o.GetDiscipline());
}

void Mark::SetDate(const std::string& data_)
{
    date = data_;
}
std::string Mark::GetDate() const
{
    return date;
}
Mark& Mark::operator=(const Mark& rhs)
{
    if(this == &rhs)
        return *this;
    SetDate(rhs.GetDate());
    SetDiscipline(rhs.GetDiscipline());
    return *this;
}
std::ostream& operator<<(std::ostream& os, const Mark &rhs)
{
    /*os << "Nota " << rhs.value << " la materia " << rhs.discipline;
    if (!rhs.date.empty())
        os << " pe data " << rhs.date;*/

    if (!rhs.date.empty())
        os << "Data " << rhs.date<<'\n';
    os<<"Materia: "<<rhs.discipline<<'\n';

    os << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, Mark &rhs)
{

    is>>rhs.discipline;
    return is;
}
void Mark::SetDiscipline(const std::string& disc)
{
    discipline = disc;
}
std::string Mark::GetDiscipline() const
{
    return discipline;
}

Mark::~Mark() = default;

Mark::Mark(std::string date_, std::string discipline_) : date(date_), discipline(discipline_) {

}

Mark::Mark(std::string discipline_) : discipline(discipline_)
{

}