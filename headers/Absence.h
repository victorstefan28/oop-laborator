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
    Absence(const std::string& tip_, const std::string& discipline_, const std::string& date_);
    Absence(const std::string& tip_, const std::string& discipline_);
    Absence& operator=(const Absence &rhs);

    Absence(const Absence& o) : Mark(o), tip(o.GetTip())
    {

    }
    std::string GetTip() const
    {
        return tip;
    }
    virtual void afiseaza(std::ostream& os) const override
    {
        os<<"Absenta "<<tip<<" la "<<GetDiscipline()<<" pe data de "<<GetDate()<<'\n';
    }
    virtual std::shared_ptr<Mark> Clone() override
    {
        return std::make_shared<Absence>(tip, GetDiscipline(), GetDate());
    }
};


#endif //CLION_PROJ_ABSENCE_H
