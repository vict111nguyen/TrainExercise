#include "fresher.h"

Fresher::Fresher(){};
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
std::string Fresher::setGraDate(const std::string& graDate){
    this -> graDate = graDate;
};
std::string Fresher::setGraRank(const std::string& gradRank){
    this -> graRank = graRank;
};