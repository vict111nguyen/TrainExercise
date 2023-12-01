#pragma once
#include "employee.h"

class Intern : public Employee{
public:
    Intern();
    Intern(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string major, int semester, std::string universityName);
    void showInfor() const;
    std::string getMajor() const;
    int getSemester() const;
    std::string getUniversityName() const;
    void setMajor(const std::string& major);
    void setSemester(const int& semester);
    void setUniversityName(const std::string& universityName);
private: 
    std::string major;
    int semester;
    std::string universityName;
};