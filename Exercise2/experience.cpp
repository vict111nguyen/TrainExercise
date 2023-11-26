#include "experience.h"

Experience::Experience(){};

Experience::Experience(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int ExpInYear, std::string ProSkill)
            : Employee(ID, fullName, birthDay, phone, email, 0),ExpInYear(ExpInYear), ProSkill(ProSkill){};

void Experience::showInfor() const {
    Employee::showInfor();
    std::cout << "ExpInYear: " << ExpInYear << std::endl;
    std::cout << "ProSkill: " << ProSkill <<std::endl;
};

int Experience::getExpInYear() const{
    return ExpInYear;
};
std::string Experience::getProskill() const{
    return ProSkill;
};
int Experience::setExpInYear(const int& Exp){
    this -> ExpInYear = Exp;
};
std::string Experience::setProSkill(const std::string& ProSkill){
    this -> ProSkill = ProSkill;
};