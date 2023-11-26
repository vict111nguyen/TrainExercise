#pragma once
#include "employee.h"

class Intern : public Employee{
public:
    Intern(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string major, int semester, std::string universityName);
    void showInfor() const;
    std::string getMajor() const;
    int getSemester() const;
    std::string getUniversityName() const;
    std::string setMajor(const std::string& major);
    int setSemester(const int& semester);
    std::string setUniversityName(const std::string& universityName);
private: 
    std::string major;
    int semester;
    std::string universityName;
};