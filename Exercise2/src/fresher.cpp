#include "../headers/fresher.h"

Fresher::Fresher():Employee::Employee(){
    std::cout << "Enter Graduation Date: " ;
    getline(std::cin, graDate);
    std::cout << "Enter Professional Skill: ";
    getline(std::cin, graRank);
};
Fresher::Fresher(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string graDate, std::string graRank)
        : Employee(ID, fullName, birthDay, phone, email, 1), graDate(graDate), graRank(graRank){};

void Fresher::showInfor() const{
    Employee::showInfor();
    std::cout << "Graduation Date: " << graDate << std::endl;
    std::cout << "Graduation Rank: " << graRank <<std::endl;
};
std::string Fresher::getGraDate() const{
    return graDate;
};
std::string Fresher::getGraRank() const{
    return graRank;
};
void Fresher::setGraDate(const std::string& graDate){
    this -> graDate = graDate;
};
void Fresher::setGraRank(const std::string& gradRank){
    this -> graRank = graRank;
};