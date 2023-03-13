#include <iostream>
#include <cstring>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#define bara "|----------------------|\n"
using namespace std;

char* todaysdate;

class Grade
{
    int value;
    char *description, *date, *discipline;
public:

    explicit Grade(int x) /// n
    {
        char aux[100] = "";
        if(todaysdate)
            strcpy(aux, todaysdate);
        else strcpy(aux, "Unknown");
        date = new char[strlen(aux)+1];
        description = new char[1];
        value = x;
        strcpy(description, "");
        strcpy(date, aux);
    };
    Grade(){};
    Grade(int x, char* data_, char *discipline_, char* observatie_ = (char*)"")
    {
        date = new char[strlen(data_)+1];

        description = new char[strlen(observatie_)+1];
        discipline = new char[strlen(discipline_)+1];
        value = x;


        strcpy(discipline, discipline_);
        strcpy(date, data_);
        strcpy(description, observatie_);

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
        os<<"Nota "<<rhs.value<<" la materia "<<rhs.discipline;
        if(strcmp(rhs.date, ""))
            os<<" pe data "<<rhs.date;
        os<<'\n';
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
    /// https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/
    ///std::vector<Grade> grades;
    uint32_t no_grades;
    uint32_t size_;
    bool activ;
    Grade* grades;

public:
    Student()
    {
        activ = 1;
    }
    Student(char* name_, char* clasa_)
    {
        name = new char[strlen(name_)+1];
        clasa = new char[strlen(clasa_)+1];
        grades = new Grade[1];
        no_grades = 0;
        size_= 1;
        activ = 1;
        strcpy(name, name_);
        strcpy(clasa, clasa_);
    }
    Student(const Student& o)
    {
        name = new char[strlen(o.name)+1];
        clasa = new char[strlen(o.clasa)+1];
        grades = new Grade[o.size_];
        no_grades = o.no_grades;
        size_= o.size_;
        strcpy(name, o.name);
        strcpy(clasa, o.clasa);
        memcpy(grades, o.grades, sizeof(Grade)*o.size_);
        activ = 1;
    }
    ~Student()
    {
        delete[] grades;
        delete[] name;
        delete[] clasa;
    }
    int GetActiv() const
    {
        return activ;
    }
    void SetActiv(bool state)
    {
        activ = state;
    }
    char* GetName() const
    {
        return name;
    }
    char* GetClasa() const
    {
        return clasa;
    }
    void SetName(char* name_)
    {
        delete[] name;
        name = new char[strlen(name_)+1];
        strcpy(name, name_);
    }
    void SetClasa(char* clasa_)
    {
        delete[] clasa;
        clasa = new char[strlen(clasa_)+1];
        strcpy(clasa, clasa_);
    }
    void add_grade(Grade obj_grade)
    {
        ///grades.push_back(obj_grade);
        if(no_grades == size_)
        {
            Grade* aux = new Grade[size_*2];
            for(uint32_t i = 0; i<size_; i++)
                aux[i] = grades[i];
            delete[] grades;
            size_*=2;
            grades = aux;
        }
        grades[no_grades]=obj_grade;
        no_grades++;

    }
    void add_grade(int value, char* discipline, char* date, char* description = (char*)"")
    {
        Grade obj(value, date, discipline, description);
        add_grade(obj);
        ///grades.push_back(obj);
        ///grades.size();
    }
    void afis(ostream& os) const
    {
        os<<"Elevul "<<name<<" are notele: \n";
        for(uint32_t i = 0; i<no_grades; i++)
            os<<i+1<<"."<<grades[i];
    }
    friend ostream& operator<<(ostream& os, Student& rhs)
    {
        rhs.afis(os);
        return os;
    }
    friend istream& operator>>(istream& is, Student& rhs)
    {
        int nota;
        char discipline[256];
        is>>nota>>discipline;


        rhs.add_grade(nota, discipline, (char*)"");
        return is;
    }
    friend void Add_Student(Student* &x, int &sz, int &no);
    Student& operator=(const Student &rhs)
    {
        SetClasa(rhs.clasa);
        SetName(rhs.name);
        grades = new Grade[rhs.size_];
        no_grades = rhs.no_grades;
        size_= rhs.size_;
        memcpy(grades, rhs.grades, sizeof(Grade)*rhs.size_);
        return *this;
    }

};
class log_instance
{
    char* message;
    char* file;
    char* user;

public:
    log_instance(char* file_)
    {
        file = new char[strlen(file_)+1];
        strcpy(file, file_);
        message = new char[1];
        user = new char[2];
        strcpy(user, "");
    }
    log_instance(char* file_, char* user_)
    {
        file = new char[strlen(file_)+1];
        strcpy(file, file_);
        user = new char[strlen(user_)+1];
        strcpy(user, user_);
    }
    ~log_instance()
    {
        delete[] message;
        delete[] user;
        delete[] file;
    }
    void push_message(char* message_)
    {
        ofstream out(file, ios_base::app);
        delete[] message;
        message = new char[strlen(message_)+1];
        strcpy(message, message_);
        if(out.is_open())
        {
            //out<<"Console:"<<message_<<"\n";
            if(strcmp(user, ""))
                out<<user<<":"<<message;
            else out<<message;
        }
        out.close();
    }
};

void Add_Student(Student* &x, uint32_t &sz, uint32_t &no, Student in)
{
    if(no == sz)
    {
        Student* aux = new Student[2*sz];
        for(uint32_t i = 0; i<sz; i++)
                aux[i] = x[i];
        delete[] x;
        sz*=2;
        x = aux;
    }
    x[no] = in;
    no++;
}
void init_date()
{
    std::time_t t = time(0);
    std::tm* now = std::localtime(&t);
    if(!now)
        return;
    char buf[32];

    strftime(buf, 32, "%d/%m/%y", now);
    strcat(buf, "\0");
    todaysdate = new char[strlen(buf)+1];
    strcpy(todaysdate, buf);
    cout<<"Data de azi este:"<<todaysdate<<"\n";
}
void erase_elev(char* file, char* elev_nume)
{
    char buf[256], aux[256];
    ifstream in(file);
    ofstream temp("temp.tmp");
    while(in.getline(buf, 255))
    {
        strcpy(aux, buf);
        char* ptr = strtok(aux, " ,");
        char nume_in[256] = "";
        strcpy(nume_in, ptr);
        strcat(nume_in, " ");
        ptr = strtok(NULL, " ,");
        strcat(nume_in, ptr);
        if(strcmp(nume_in, elev_nume))
            temp<<buf<<"\n";
    }
    in.close();
    temp.close();
    remove(file);
    rename("temp.tmp", file);

}


int main()
{
    init_date();
    log_instance log((char*)"logs.log", (char*)"Console");
    log_instance grade_file((char*)("note.in"));
    log_instance elevi_file((char*)"elevi.in");
    Student* Students = new Student[1];
    uint32_t no_students = 0;
    uint32_t sz_students = 1;
    int opt = 0;
    ifstream in("elevi.in");
    char nume[1024], prenume[256];
    char clasa[256];
    while(in>>nume>>prenume>>clasa)
    {
        strcat(nume, " ");
        strcat(nume, prenume);
        Student o(nume, clasa);
        Add_Student(Students, sz_students, no_students, o);

    }
    ifstream read_note("note.in");
    char line[1024] = "";
    while(read_note.getline(line, 1024))
    {
        char nume[128] = "", data[128] = "", materie[128] = "";
        int nota = 0;

        char* ptr = strtok(line, ",");
        for(int i = 0; i<=3; i++)
        {
            if(!ptr)
                continue;

            if(i==0)
                strcpy(nume, ptr);
            if(i==1)
            {
                if(strlen(ptr)==2)
                    nota = (ptr[0]-'0')*10+(ptr[1]-'0');
                else nota = (ptr[0]-'0');
            }
            if(i==2)
                strcpy(materie, ptr);
            if(i==3)
                strcpy(data, ptr);
            ptr = strtok(NULL, ",");
        }

        for(uint32_t i = 0; i<no_students; i++)
            if(!strcmp(nume, Students[i].GetName()))
                Students[i].add_grade(nota, materie, data);

    }
    read_note.close();
    in.close();
    do{
start:
        cout<<bara;
        cout<<"Alege o optiune de mai jos\n";
        cout<<"1.Afiseaza/modifica lista elevi\n";
        cout<<"2.Adauga elev\n";
        cout<<"0.Inchide programul\n";
        cout<<bara;
        cin>>opt;
        if(opt == 1)
        {

            cout<<"Elevii introdusi in catalog sunt: \n"<<bara;
            for(uint32_t i = 0; i<no_students; i++)
                if(Students[i].GetActiv())
                    cout<<i+1<<". "<<Students[i].GetName()<<' '<<Students[i].GetClasa()<<'\n';
            cout<<bara;
            int opt2 = 0;
            cout<<"Introdu id-ul unui elev pentru a efectua o modificare asupra acestuia, 0 daca nu doresti sa accesezi un elev\n"<<bara;
            int id = -1;
            cin>>id;
            id-=1;
            if(id == -1 || Students[id].GetActiv() == false)
                goto start;
            cout<<Students[id];
            cout<<bara;
            cout<<"Introdu tipul modificarii pe care doresti sa o faci:\n1.Adauga nota\n2.Sterge elev\n"<<bara;
            cin>>opt2;
            if(opt2 == 1)
            {
                cout<<"Introdu valoarea notei:\n";
                int nota;
                cin>>nota;
                cout<<"Introdu materia:\n";
                char materie[32];
                cin>>materie;
                Students[id].add_grade(nota, materie, todaysdate);
                char buf_log[128] = "";
                sprintf(buf_log, "Elevul %s a primit nota %d; data: %s\n", Students[id].GetName(), nota, todaysdate);
                char buf_note[256] = "";
                sprintf(buf_note, "%s,%d,%s,%s\n", Students[id].GetName(), nota, materie, todaysdate);
                log.push_message(buf_log);
                grade_file.push_message(buf_note);
            }
            if(opt2 == 2)
            {
                cout<<"Esti sigur ca vrei sa stergi elevul cu id "<<id<<": "<<Students[id].GetName()<<"[y/n] \n";
                char yn;
                cin>>yn;
                if(yn == 'y' || yn == 'Y')
                {
                    Students[id].SetActiv(false);

                    erase_elev((char*)"elevi.in", Students[id].GetName());
                    erase_elev((char*)"note.in", Students[id].GetName());
                    char push[64];
                    sprintf(push, "Elevul %s sters\n", Students[id].GetName());
                }
            }
        }
        if(opt == 2)
        {

            cout<<"Introdu numele\n";
            char namee[256] = "", prenumee[256] = "";
            cin>>namee;
            cout<<"Introdu prenumele\n";
            cin>>prenumee;
            strcat(namee, " ");
            strcat(namee, prenumee);
            cout<<"Introdu clasa din care face parte:\n";
            char clasaa[16];
            cin>>clasaa;
            Add_Student(Students, sz_students, no_students, Student(namee, clasaa));
            char push[256];
            sprintf(push, "%s %s\n", namee, clasaa);
            elevi_file.push_message(push);
            sprintf(push, "Elev adaugat: %s\n", namee);
            log.push_message(push);
        }
    }while(opt != 0);

    delete[] Students;
    return 0;
}
