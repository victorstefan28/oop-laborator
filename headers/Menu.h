//
// Created by vik on 4/24/2023.
//

#ifndef CLION_PROJ_MENU_H
#define CLION_PROJ_MENU_H
#include "headers.h"
#define bara "|----------------------|\n"

class log_instance
{
    std::string message;
    std::string file;
    std::string user;

public:
    explicit log_instance(std::string file_)
    {
        file = file_;
        message = "";
        user = "";
    }
    log_instance(std::string file_, std::string user_)
    {
        file = file_;
        user = user_;
        message = "";
    }
    ~log_instance()
    {

    }
    void push_message(std::string s_message_)
    {
        if(s_message_.empty())
            throw input_exception("Trying to parse empty string to output file" + file);
        auto message_ = s_message_.c_str();
        std::ofstream out(file, std::ios_base::app);
        message = s_message_;
        if(out.is_open())
        {
            //out<<"Console:"<<message_<<"\n";
            if(strcmp(user.c_str(), ""))
                out<<user<<":"<<message;
            else out<<message;
        }
        out.close();
    }
};

class Menu {
    inline static std::string todays_date;
public:
    static std::string GetDate()
    {
        return todays_date;
    }
    Menu()
    {
        SetDate();
    }
    static void SetDate();
    void Add_Student(std::vector<std::shared_ptr<Student>>& x, Student in);
    void erase_elev(const std::string& s_file, const std::string& s_elev_nume, int line_no);
    void run();
};
/*void Add_Student(Student* &x, uint32_t &sz, uint32_t &no, const Student in)
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
void erase_elev(const std::string& s_file, const std::string& s_elev_nume)
{
    char buf[256], aux[256];
    auto file = s_file.c_str();
    auto elev_nume = s_elev_nume.c_str();
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

}*/


#endif //CLION_PROJ_MENU_H
