//
// Created by vik on 4/26/2023.
//
#include "../headers/headers.h"
Student::Student()
{
    activ = 1;
    clasa = "";
    name = "";

}
Student::Student(std::string name_, std::string clasa_)
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
Student::Student(const Student& o)
{
    name = o.GetName();
    clasa = o.GetClasa();

    /*strcpy(name, o.name);
    strcpy(clasa, o.clasa);
    memcpy((void*)grades, (void*)o.grades, sizeof(Grade)*o.size_);*/
    activ = o.GetActiv();
}
~Student::Student()
{
    marks.clear();
}
int Student::GetActiv() const
{
    return activ;
}
void Student::SetActiv(bool state)
{
    activ = state;
}
[[nodiscard]] std::string Student::GetName() const
{
    return name;
}
[[nodiscard]] std::string Student::GetClasa() const
{
    return clasa;
}
void Student::SetName(std::string name_)
{
    name = name_;
}
void Student::SetClasa(std::string clasa_)
{
    clasa = clasa_;
}
void Student::add_grade(const Grade obj_grade)
{
    auto o = std::make_shared<Grade>(obj_grade);
    Mark::incrementNoMarks();
    marks.push_back(o);
}
void Student::add_grade(int value, std::string discipline, std::string date)
{
    Grade obj(value, discipline, date);
    if(value < 0 || value > 10)
        throw invalid_arg("Value argument passed in add_grade is invalid");
    add_grade(obj);
}
void Student::add_absenta(const Absence o_abs)
{
    auto o = std::make_shared<Absence>(o_abs);
    Mark::incrementNoMarks();
    marks.push_back(o);
}
std::vector<std::shared_ptr<Mark>>& Student::GetMarks()
{
    return marks;
}
void Student::afis(std::ostream& os) const
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
std::ostream& operator<<(std::ostream& os, const Student& rhs)
{
    rhs.afis(os);
    return os;
}
std::istream& operator>>(std::istream& is, Student& rhs)
{
    int nota;
    std::string discipline;
    is>>nota;
    is>>discipline;


    rhs.add_grade(nota, discipline, "");
    return is;
}

Student& Student::operator=(const Student &rhs)
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