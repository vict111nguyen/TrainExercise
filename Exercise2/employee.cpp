#include "employee.h"

Employee::Employee(){};

Employee::Employee(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int EmpType)
        :ID(ID), fullName(fullName),birthDay(birthDay), phone(phone),email(email), EmpType(EmpType),  EmpCount(0){};


void Employee::AddCertificate(std::shared_ptr<Certificate> cert){
    certificates.push_back(cert);
}

int Employee::getID() const{
    return ID;
}

std::string Employee::getName() const{
    return fullName;
}

std::string Employee::getBirthday() const{
    return birthDay;
};
std::string Employee::getPhone(){
    return phone;
};
std::string Employee::getEmail(){
    return email;
};
int Employee::getEmpType(){
    return EmpType;
}

std::string Employee::setName(const std::string& name){
    this -> fullName = name;
};
std::string Employee::setBirthday(const std::string& birthDay){
    this ->birthDay = birthDay;
};
std::string Employee::setPhone(const std::string& Phone){
    this -> phone = Phone;
};
std::string Employee::setEmail(const std::string& email){
    this -> email = email;
};

void Employee::showInfor() const{
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Name: " << fullName << std::endl;
    std::cout << "Birthday: " << birthDay << std::endl;
    std::cout << "Phone Number: " << phone << std::endl;
    std::cout << "Email: " << email << std::endl;
}

static int CountEmployees = 0;



