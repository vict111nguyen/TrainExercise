#include "../headers/intern.h"

Intern::Intern() : Employee::Employee(){
    std::cout << "Enter Major: " ;
    getline(std::cin, major);
    std::cout << "Enter semester: ";
    std::cin>> semester; std::cin.ignore();
    std::cout << "Enter University Name: ";
    getline(std::cin, universityName);
}

Intern::Intern(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string major, int semester, std::string universityName)
            : Employee(ID, fullName, birthDay, phone, email, 2), major(major), semester(semester), universityName(universityName){};

void Intern::showInfor() const{
    Employee::showInfor();
    std::cout << "Major: " << major << std::endl;
    std::cout << "Semester: " << semester << std::endl;
    std::cout << "Univerity Name: " << universityName << std::endl;

};
std::string Intern::getMajor() const{
    return major;
};
int Intern::getSemester() const{
    return semester;
};
std::string Intern::getUniversityName() const{
    return universityName;
};
void Intern::setMajor(const std::string& major){
    this -> major = major;
};
void Intern::setSemester(const int& semester){
    this -> semester = semester;
};
void Intern::setUniversityName(const std::string& universityName){
    this -> universityName = universityName;
};
