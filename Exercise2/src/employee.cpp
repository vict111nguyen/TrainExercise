#include "../headers/employee.h"
#include "../headers/validator.h"

Employee::Employee(){
    std::cout << "\nEnter ID: ";
    std::cin >> ID; std::cin.ignore();

    bool validInput = false;
    while(!validInput){
        try
        {
            std::cout << "Enter name: ";
            getline(std::cin, fullName); 
            Validator::ValidateFullName(fullName);
            validInput = true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    validInput = false;
    while (!validInput)
    {
        try
        {
            std::cout << "Enter Date of birth: ";
            getline(std::cin, birthDay); 
            Validator::ValidateBirthDay(birthDay); 
            validInput = true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    validInput = false;
    while (!validInput)
    {
        try
        {
            std::cout << "Enter Phone number: ";
            getline(std::cin, phone); 
            Validator::ValidatePhone(phone);
            validInput = true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    validInput = false;
    while (!validInput)
    {
        try
        {
            std::cout << "Enter Email: ";
            getline(std::cin, email); 
            Validator::ValidateEmail(email);
            validInput = true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }  
    }
    

};

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

void Employee::setName(const std::string& name){
    this -> fullName = name;
};
void Employee::setBirthday(const std::string& birthDay){
    this ->birthDay = birthDay;
};
void Employee::setPhone(const std::string& Phone){
    this -> phone = Phone;
};
void Employee::setEmail(const std::string& email){
    this -> email = email;
};

void Employee::showInfor() const{
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Name: " << fullName << std::endl;
    std::cout << "Birthday: " << birthDay << std::endl;
    std::cout << "Phone Number: " << phone << std::endl;
    std::cout << "Email: " << email << std::endl;
}

// static int CountEmployees = 0;



