//
// Created by vik on 4/10/2023.
//

#ifndef CLION_PROJ_GRADE_H
#define CLION_PROJ_GRADE_H

#include "mark.h"

class Grade : public Mark {
    int value;

public:
    int GetValue() const;
    void SetValue(int val);
    Grade(const Grade& o) : Mark(o)
    {
        value = o.GetValue();
    }
    Grade(int value_, const std::string& discipline_, const std::string& date_);
    Grade(int value_, const std::string& discipline_);
    virtual void afiseaza(std::ostream& os) const override;
    bool operator==(const Grade &rhs) const;
    bool operator!=(const Grade &rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Grade &rhs);
    Grade& operator=(const Grade &rhs);
};


#endif //CLION_PROJ_GRADE_H
