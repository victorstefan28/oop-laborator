//
// Created by vik on 4/7/2023.
//

#ifndef CLION_PROJ_MARK_H
#define CLION_PROJ_MARK_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

//
class Mark
{
protected:
    std::string date, discipline;
    inline static int no_marks;
public:
    Mark(const Mark &o);
    Mark();
    static void incrementNoMarks() { no_marks++;}
    static int getNoMarks() {
        return no_marks;
    }
    [[maybe_unused]] Mark(int) = delete;
    Mark(std::string date_, std::string discipline_);
    explicit Mark(std::string discipline_);
    Mark& operator=(const Mark& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Mark &rhs);
    friend std::istream& operator>>(std::istream& is, Mark &rhs);

    void SetDiscipline(const std::string& disc);
    [[nodiscard]] std::string GetDiscipline() const;
    void SetDate(const std::string& data_);
    [[nodiscard]] std::string GetDate() const;
    virtual void afiseaza(std::ostream& os) const = 0;
    virtual ~Mark();

};


#endif //CLION_PROJ_MARK_H
