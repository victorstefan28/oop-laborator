//
// Created by vik on 4/24/2023.
//

#ifndef CLION_PROJ_STUDENT_H
#define CLION_PROJ_STUDENT_H
#include "headers.h"
#include "Absence.h"


class Student
{
    std::string name;
    std::string clasa;
    std::vector<std::shared_ptr<Mark>> marks;
    bool activ;

public:
    Student()
    {
        activ = 1;
        clasa = "";
        name = "";

    }
    Student(std::string name_, std::string clasa_)
    {
        /*name = new char[strlen(name_)+1];
        clasa = new char[strlen(clasa_)+1];
        grades = new Grade[1];
        no_grades = 0;
        size_= 1;*/
        name = name_;
        clasa = clasa_;
        activ = 1;


    }
    Student(const Student& o)
    {
        name = o.GetName();
        clasa = o.GetClasa();

        /*strcpy(name, o.name);
        strcpy(clasa, o.clasa);
        memcpy((void*)grades, (void*)o.grades, sizeof(Grade)*o.size_);*/
        activ = o.GetActiv();
    }
    ~Student()
    {
        marks.clear();
    }
    int GetActiv() const
    {
        return activ;
    }
    void SetActiv(bool state)
    {
        activ = state;
    }
    [[nodiscard]] std::string GetName() const
    {
        return name;
    }
    [[nodiscard]] std::string GetClasa() const
    {
        return clasa;
    }
    void SetName(std::string name_)
    {
        name = name_;
    }
    void SetClasa(std::string clasa_)
    {
        clasa = clasa_;
    }
    void add_grade(const Grade obj_grade)
    {
        auto o = std::make_shared<Grade>(obj_grade);
        o->incrementNoMarks();
        marks.push_back(o);
    }
    void add_grade(int value, std::string discipline, std::string date)
    {
        Grade obj(value, discipline, date);
        add_grade(obj);
    }
    void add_absenta(const Absence o_abs)
    {
        auto o = std::make_shared<Absence>(o_abs);
        o->incrementNoMarks();
        marks.push_back(o);
    }
    std::vector<std::shared_ptr<Mark>>& GetMarks()
    {
        return marks;
    }
    void afis(std::ostream& os) const
    {
        os<<"Elevul "<<name<<" are mark-urile: \n";
        for(size_t i = 0; i<marks.size(); i++)
            try{
                std::cout<<"ID:"<<i<<'|';
                marks.at(i)->afiseaza(os);
            }
            catch(std::out_of_range& exception)
            {
                std::cout<<"Out of range";
            }
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& rhs)
    {
        rhs.afis(os);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Student& rhs)
    {
        int nota;
        std::string discipline;
        is>>nota;
        is>>discipline;


        rhs.add_grade(nota, discipline, "");
        return is;
    }

    Student& operator=(const Student &rhs)
    {
        if(this == &rhs)
            return *this;
        SetClasa(rhs.clasa);
        SetName(rhs.name);
        /*grades = new Grade[rhs.size_];
        no_grades = rhs.no_grades;
        size_= rhs.size_;
        memcpy((void*)grades, (void*)rhs.grades, sizeof(Grade)*rhs.size_);*/
        marks = rhs.marks;
        return *this;
    }

};
#endif //CLION_PROJ_STUDENT_H
