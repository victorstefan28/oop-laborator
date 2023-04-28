//
// Created by vik on 4/24/2023.
//
#include "../headers/headers.h"

void Menu::SetDate()
{
    std::time_t t = time(0);
    std::tm* now = std::localtime(&t);
    if(!now)
        return;
    char buf[32];

    strftime(buf, 32, "%d/%m/%y", now);
    strcat(buf, "\0");
    todays_date = buf;
    std::cout<<"Data de azi este:"<<todays_date<<"\n";
}



void Menu::Add_Student(std::vector<std::shared_ptr<Student>>& x, const Student in)
{
    x.push_back(std::make_shared<Student>(in));
}
void Menu::erase_elev(const std::string& s_file, const std::string& s_elev_nume, int line_no = -1)
{
    char buf[256], aux[256];
    int ct = 0;
    auto file = s_file.c_str();
    auto elev_nume = s_elev_nume.c_str();
    std::ifstream in(file);
    std::ofstream temp("temp.tmp");
    while(in.getline(buf, 255))
    {
        strcpy(aux, buf);
        char* ptr = strtok(aux, " ,");
        char nume_in[256] = "";
        strcpy(nume_in, ptr);
        strcat(nume_in, " ");
        ptr = strtok(nullptr, " ,");
        strcat(nume_in, ptr);
        if(!strcmp(nume_in, elev_nume))
        {

            if(line_no == -1 || (line_no != -1 && ct != line_no))
                temp<<buf<<'\n';
            ct++;
        }
        else temp<<buf<<'\n';
            /*    temp<<buf<<"\n";*/
    }
    in.close();
    temp.close();
    remove(file);
    rename("temp.tmp", file);
}

void Menu::run()
{
    log_instance log((std::string)"logs.log", (std::string)"Console");
    log_instance grade_file((std::string)("note.in"));
    log_instance elevi_file((std::string)"elevi.in");
    std::vector<std::shared_ptr<Student>> Students;
    /*uint32_t no_students = 0;
    uint32_t sz_students = 1;*/
    int opt = 0;
    std::ifstream in("elevi.in");
    /*char nume[1024], prenume[256];
    char clasa[256];*/
    std::string nume, prenume, clasa;
    while(in>>nume>>prenume>>clasa)
    {
        /*strcat(nume, " ");
        strcat(nume, prenume);*/
        try {
            nume += " " + prenume;
            if(nume.empty() || std::any_of(nume.begin(), nume.end(), ::isdigit))
                throw input_exception("Invalid name");
            if(clasa.empty())
                throw input_exception("Invalid class name");
            /*std::cout << nume << '\n';*/
            Student o(nume, clasa);
            Add_Student(Students, o);
            //Students.back()->afis(std::cout);
        }
        catch(input_exception& e)
        {
            std::cout<<e.what();
            return;
        }
    }

    std::ifstream read_note("note.in");
    char line[1024] = "";
    while(read_note.getline(line, 1024))
    {
        //char numeeee[128] = "", data[128] = "", materie[128] = "";
        std::string numee, data, materie;
        int nota = 0;
        char *ptr = strtok(line, ",");
        bool is_abs = false;
        std::string abs_type = "";
        for(int i = 0; i<=3; i++)
        {
            if(!ptr)
                continue;

            if(i==0)
            {
                try{
                    if(!ptr)
                        throw input_exception("Invalid input reading the grades");
                    numee = std::string(ptr);
                }
                catch(input_exception &e)
                {
                    std::cout<<e.what();
                    return;
                }
            }
            if(i==1)
            {
                std::string strg = std::string(ptr);
                if(std::any_of(strg.begin(), strg.end(), ::isdigit)){
                    if (strlen(ptr) == 2)
                        nota = (ptr[0] - '0') * 10 + (ptr[1] - '0');
                    else nota = (ptr[0] - '0');
                    is_abs = false;
                }
                else
                {
                    is_abs = true;
                    abs_type = std::string(ptr);
                }
            }
            if(i==2)
            {
                try{
                    if(!ptr)
                        throw input_exception("Invalid input reading the grades");
                    materie = std::string(ptr);
                }
                catch(input_exception &e)
                {
                    std::cout<<e.what();
                    return;
                }
            }
            if(i==3)
            {
                try{
                    if(!ptr)
                        throw input_exception("Invalid input reading the grades");
                    data = std::string(ptr);
                }
                catch(input_exception &e)
                {
                    std::cout<<e.what();
                    return;
                }
            }
            ptr = strtok(NULL, ",");

        }

        for(uint32_t i = 0; i<Students.size(); i++)
            if(numee == Students[i]->GetName()){
                //std::cout<<"gasit nota "<<Students[i]->GetName();
                if(!is_abs)
                    Students[i]->add_grade(nota, materie, data);
                else
                    Students[i]->add_absenta(Absence(abs_type, materie, data));
            }

    }
    read_note.close();
    in.close();
    do{
        start:
        std::cout<<bara;
        std::cout<<"Alege o optiune de mai jos\n";
        std::cout<<"1.Afiseaza/modifica lista elevi\n";
        std::cout<<"2.Adauga elev\n";
        std::cout<<"0.Inchide programul\n";
        std::cout<<bara;
        std::cin>>opt;
        if(opt == 1)
        {

            std::cout<<"Elevii introdusi in catalog sunt: \n"<<bara;
            for(uint32_t i = 0; i<Students.size(); i++)
                if(Students[i]->GetActiv())
                    std::cout<<i+1<<". "<<Students[i]->GetName()<<' '<<Students[i]->GetClasa()<<'\n';
            std::cout<<bara;
            int opt2 = 0;
            std::cout<<"Introdu id-ul unui elev pentru a efectua o modificare asupra acestuia, 0 daca nu doresti sa accesezi un elev\n"<<bara;
            int id = -1;
            /*std::cin>>id;
            id-=1;
            if(id == -1 || Students[id]->GetActiv() == false)
                goto start;*/
            try{
                std::cin>>id;
                id-=1;
                if(id == -1 || Students[id]->GetActiv() == false)
                    throw input_exception("ID invalid");
            }
            catch(input_exception &e)
            {
                std::cout<<e.what();
                goto start;
            }
            Students[id]->afis(std::cout);
            std::cout<<bara;
            std::cout<<"Introdu tipul modificarii pe care doresti sa o faci:\n1.Adauga nota\n2.Adauga absenta\n3.Sterge elev\n4.Sterge mark\n"<<bara;
            //std::cin>>opt2;
            try{
                std::cin>>opt2;
                if(opt2 > 4 || opt2 < 0)
                    throw input_exception("Optiune invalida");
            }
            catch(input_exception &e)
            {
                std::cout<<e.what();
            }
            if(opt2 == 1)
            {
                std::cout<<"Introdu valoarea notei:\n";
                try{
                    int nota;
                    std::cin >> nota;
                    std::cout << "Introdu materia:\n";
                    std::string materiee;
                    std::cin>>materiee;
                    Students[id]->add_grade(nota, materiee, GetDate());
                    char buf_log[2048] = "";
                    snprintf(buf_log, 2048, "Elevul %s a primit nota %d; data: %s\n", Students[id]->GetName().c_str(),
                             nota, GetDate().c_str());
                    char buf_note[2048] = "";
                    snprintf(buf_note, 2048, "%s,%d,%s,%s\n", Students[id]->GetName().c_str(), nota, materiee.c_str(),
                             GetDate().c_str());
                    log.push_message(buf_log);
                    grade_file.push_message(buf_note);

                }
                catch(input_exception &e)
                {
                    std::cout<<e.what();

                }

            }
            if(opt2 == 2)
            {

                std::string type_a;
                std::cout<<"Introdu tipul absentei:\n";
                std::cin>>type_a;
                std::cout << "Introdu materia:\n";
                std::string materiee;
                std::cin>>materiee;
                char buf_note[2048] = "";
                snprintf(buf_note, 2048, "%s,%s,%s,%s\n", Students[id]->GetName().c_str(), type_a.c_str(), materiee.c_str(),
                         GetDate().c_str());
                //log.push_message(buf_log);
                grade_file.push_message(buf_note);
                Students[id]->add_absenta(Absence(type_a, materiee, GetDate()));
            }
            if(opt2 == 3)
            {
                std::cout<<"Esti sigur ca vrei sa stergi elevul cu id "<<id<<": "<<Students[id]->GetName()<<"[y/n] \n";
                char yn;
                std::cin>>yn;
                if(yn == 'y' || yn == 'Y')
                {
                    Students[id]->SetActiv(false);

                    erase_elev((std::string)"elevi.in", Students[id]->GetName());
                    erase_elev((std::string)"note.in", Students[id]->GetName());
                    char push[2048];
                    snprintf(push, 2048, "Elevul %s sters\n", Students[id]->GetName().c_str());

                }
            }
            if(opt2 == 4)
            {
                std::cout<<"Introdu id-ul mark-ului pe care doresti sa il stergi\n";
                int del_id = -1;
                std::cin>>del_id;
                auto& vec = Students[id]->GetMarks();
                vec.erase(vec.begin() + (del_id));
                erase_elev("note.in", Students[id]->GetName(), del_id);
            }
        }
        if(opt == 2)
        {

            try{
                std::cout << "Introdu numele\n";
                char namee[256] = "", prenumee[256] = "";
                std::cin >> namee;
                std::cout << "Introdu prenumele\n";
                std::cin >> prenumee;
                strcat(namee, " ");
                strcat(namee, prenumee);
                std::cout << "Introdu clasa din care face parte:\n";
                if(strlen(namee) == 0)
                    throw input_exception("Invalid name");
                char clasaa[16];
                std::cin >> clasaa;
                Add_Student(Students, Student(namee, clasaa));
                char push[2048];
                snprintf(push, 2048, "%s %s\n", namee, clasaa);
                elevi_file.push_message(push);
                snprintf(push, 2048, "Elev adaugat: %s\n", namee);
                log.push_message(push);
            }
            catch(input_exception &e)
            {
                std::cout<<e.what();

            }
        }
    }while(opt != 0);

    Students.clear();
}