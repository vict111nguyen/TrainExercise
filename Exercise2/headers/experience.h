#pragma once
#include "employee.h"

class Experience : public Employee
{
public:
    Experience();
    Experience(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int ExpInYear, std::string ProSkill);
    void showInfor() const;

    int getExpInYear() const;
    std::string getProskill() const;
    void setExpInYear(const int& Exp);
    void setProSkill(const std::string& ProSkill);
    
private:
    int ExpInYear;
    std::string ProSkill;
};