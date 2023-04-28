//
// Created by vik on 4/24/2023.
//

#ifndef CLION_PROJ_ABSENCE_H
#define CLION_PROJ_ABSENCE_H
#include "headers.h"

class Absence : public Mark {
    std::string tip;
public:
    Absence();
    Absence(std::string tip_, std::string discipline_, std::string date_);
    Absence(std::string tip_, std::string discipline_);
    Absence& operator=(const Absence &rhs);

    Absence(const Absence& o) : Mark(o)
    {
        tip = o.GetTip();
    }
    std::string GetTip() const
    {
        return tip;
    }
    virtual void afiseaza(std::ostream& os) const
    {
        os<<"Absenta "<<tip<<" la "<<GetDiscipline()<<" pe data de "<<GetDate()<<'\n';
    }
};


#endif //CLION_PROJ_ABSENCE_H
