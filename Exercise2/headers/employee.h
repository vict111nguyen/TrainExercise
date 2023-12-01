#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "certificate.h"

class Employee{
public:    
    Employee();
    Employee(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int EmpType);
    
    void AddCertificate(std::shared_ptr<Certificate> cert);

    int getID() const;
    std::string getName() const;
    std::string getBirthday() const ;
    std::string getPhone();
    std::string getEmail();
    int getEmpType();

    void setName(const std::string& name);
    void setBirthday(const std::string& birthDay);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    void showInfor() const;

    // static int CountEmployees;

    virtual ~Employee(){};

protected: 
    int ID;
    std::string fullName;
    std::string birthDay;
    std::string phone;
    std::string email;
    int EmpType;
    int EmpCount;
    std::vector<std::shared_ptr<Certificate>> certificates;
};