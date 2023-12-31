#pragma once
#include "employee.h"

class Fresher : public Employee{
public:
    Fresher();
    Fresher(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string graDate, std::string graRank);
    void showInfor() const;
    std::string getGraDate() const;
    std::string getGraRank() const;
    void setGraDate(const std::string& graDate);
    void setGraRank(const std::string& gradRank);
    
private:
    std::string graDate;
    std::string graRank;
};