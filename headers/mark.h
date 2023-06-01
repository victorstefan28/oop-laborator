//
// Created by vik on 4/7/2023.
//

#ifndef CLION_PROJ_MARK_H
#define CLION_PROJ_MARK_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <memory>
//

class Mark
{
protected:
    std::string date, discipline;

public:
    Mark(const Mark &o);
    Mark();

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
    virtual std::shared_ptr<Mark> Clone() = 0;

};


#endif //CLION_PROJ_MARK_H
