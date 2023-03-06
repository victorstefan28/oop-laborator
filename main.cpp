#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Grade
{
    int value;
    char *description, *date, *discipline;
public:

    explicit Grade(int x) /// n
    {
        date = new char[strlen("Unknown")+1];
        description = new char[1];
        value = x;
        strcpy(description, "");
        strcpy(date, "Unknown");
    };
    Grade(int x, char* data_, char* observatie_ = "\0", char *discipline_ = "")
    {
        date = new char[strlen(data_)+1];

        description = new char[strlen(observatie_)+1];
        discipline = new char[strlen(discipline_)+1];
        value = x;


        strcpy(discipline, discipline_);
        if (strlen(data_) < 32)
            strcpy(date, data_);
        else cout<<"Data invalida, seteaza data notei!\n";

        if(strlen(observatie_) > 256)
            strcpy(description, observatie_);
        else description = "";


    }
    ~Grade()
    {
        delete[] description;
        delete[] date;
        delete[] discipline;
    }
    Grade(const Grade& o)
    {
        value = o.value;

        date = new char[strlen(o.date)+1];

        description = new char[strlen(o.description)+1];
        discipline = new char[strlen(o.discipline)+1];

        strcpy(description, o.description);
        strcpy(date, o.date);
        strcpy(discipline, o.discipline);
    }
    void SetNota(int valoare_)
    {
        value = valoare_;
    }
    void SetData(char* data_)
    {
        delete[] date;
        date = new char[strlen(data_)+1];

        strcpy(date, data_);
    }
    void SetDescriere(char* desc)
    {
        delete[] description;

        description = new char[strlen(desc)+1];
        strcpy(description, desc);
    }
    void SetDiscipline(char* discipline_)
    {
        delete[] discipline;
        discipline = new char[strlen(discipline_)+1];
        strcpy(discipline, discipline_);
    }
    const int GetGrade() const
    {
        return value;
    }
    const char* GetDate() const
    {
        return date;
    }
    const char* GetDescription() const
    {
        return description;
    }
    const char* GetDiscipline() const
    {
        return discipline;
    }
    bool operator==(Grade &rhs) const
    {
        return strcmp(rhs.discipline, discipline) && value == rhs.value;
    }
    bool operator!=(Grade &rhs) const
    {
        return !(*this == rhs);
    }
    Grade& operator=(const Grade& rhs)
    {
        SetData(rhs.date);
        SetDescriere(rhs.description);
        SetNota(rhs.value);
        SetDiscipline(rhs.discipline);

        return *this;
    }
    friend ostream& operator<<(ostream& os, const Grade &rhs)
    {
        os<<"Nota "<<rhs.value<<" la materia "<<rhs.discipline<<'\n';
        return os;
    }
    friend istream& operator>>(istream& is, Grade &rhs)
    {
        is>>rhs.value>>rhs.discipline;
        return is;
    }

};

class Student
{
    char* name;
    char* clasa;

    std::vector<Grade> grades;
public:
    Student(char* name_, char* clasa_)
    {
        name = new char[strlen(name_)+1];
        clasa = new char[strlen(clasa_)+1];

        strcpy(name, name_);
        strcpy(clasa, clasa_);
    }
    void add_grade(Grade obj_grade)
    {
        grades.push_back(obj_grade);
    }
    void add_grade(int value, char* discipline, char* date, char* description = "")
    {
        Grade obj(value, date, description, discipline);
        grades.push_back(obj);
        grades.size();
    }
    void afis(ostream& os)
    {
        os<<"Elevul "<<name<<" are: \n";
        for (auto x : grades)
            os<<x;
    }
    friend ostream& operator<<(ostream& os, Student& rhs)
    {
        rhs.afis(os);
        return os;
    }
};


int main()
{
    Student Andrei("Andrei", "12A");
    Grade nota(5, "azi", "", "Matematica");
    Andrei.add_grade(nota);
    Andrei.add_grade(1, "Lb. Roamana", "ieri", "copiat");
    cout<<Andrei;
    return 0;
}
