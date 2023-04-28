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
    Student();

    Student(std::string name_, std::string clasa_);
    Student(const Student& o);
    ~Student();
    int GetActiv() const;
    void SetActiv(bool state);

    [[nodiscard]] std::string GetName() const;
    [[nodiscard]] std::string GetClasa() const;
    void SetName(std::string name_);
    void SetClasa(std::string clasa_);
    void add_grade(const Grade obj_grade);
    void add_grade(int value, std::string discipline, std::string date);
    void add_absenta(const Absence o_abs);
    std::vector<std::shared_ptr<Mark>>& GetMarks();
    void afis(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
    friend std::istream& operator>>(std::istream& is, Student& rhs);
    Student& operator=(const Student &rhs);

};
#endif //CLION_PROJ_STUDENT_H
