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
    int setExpInYear(const int& Exp);
    std::string setProSkill(const std::string& ProSkill);
    
private:
    int ExpInYear;
    std::string ProSkill;
};