#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Certificate{
public: 
    Certificate(int CertificatedID, std::string CertificateName, std::string CertificateRank, std::string CertificatedDate) 
                : CertificatedID(CertificatedID), CertificateName(CertificateName), CertificateRank(CertificateRank), CertificatedDate(CertificatedDate){};
private: 
    int CertificatedID;
    std::string CertificateName;
    std::string CertificateRank;
    std::string CertificatedDate;
};

class Employee{
public:    
    Employee(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int employee_type)
            :ID(ID), fullName(fullName),birthDay(birthDay), phone(phone),email(email), employee_type(employee_type),  employee_count(0){};
    virtual void showInfor() const = 0;
    
    void AddCertificate(const Certificate& cert){
        certificates.push_back(cert);
    }

    int getID(){
        return ID;
    }

    static int CountEmployees;

    virtual ~Employee(){};

protected: 
    int ID;
    std::string fullName;
    std::string birthDay;
    std::string phone;
    std::string email;
    int employee_type;
    int employee_count;
    std::vector<Certificate> certificates;
};

class Experience : public Employee
{
public:
    Experience(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, int ExpInYear, std::string ProSkill)
            : Employee(ID, fullName, birthDay, phone, email, 0),ExpInYear(ExpInYear), ProSkill(ProSkill){};
    void showInfor() const override{

    }
    
private:
    int ExpInYear;
    std::string ProSkill;
};

class Fresher : public Employee {
public:
    Fresher(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string Grad_date, std::string Grad_rank)
            : Employee(ID, fullName, birthDay, phone, email, 1), Grad_date(Grad_date), Grad_rank(Grad_rank){};
    void showInfor() const override{

    }
    
private:
    std::string Grad_date;
    std::string Grad_rank;
};

class Intern : public Employee {
public:
    Intern(int ID, std::string fullName, std::string birthDay, std::string phone, std::string email, std::string major, std::string semester, std::string universityName)
            : Employee(ID, fullName, birthDay, phone, email, 2), major(major), semester(semester), universityName(universityName){};
    void showInfor() const override{

    }
private: 
    std::string major;
    std::string semester;
    std::string universityName;

};

int Employee::CountEmployees = 0;

bool isValidName(const std::string& name){

}
bool isValidBirthday(const std::string& birthday){

}
bool isValidPhoneNumber(const std::string& phone){

}
bool isValidEmail(const std::string& email){

}


void AddEmployee(std::vector<std::shared_ptr<Employee>>& employees, const std::shared_ptr<Employee>& newEmployee){
    employees.push_back(newEmployee);
    Employee::CountEmployees++;
}

void EditEmployee(std::vector<std::shared_ptr<Employee>>& employees, int ID){
    //Tìm nhan vien theo ID và dieu chinh thong tin
    bool Found = false;
    for(const auto& emp : employees){
        if(emp -> getID() == ID){
            //Chinh sua thong tin o day
        }

        emp -> showInfor();
        Found = true;
        break;
    }
    if(!Found){
        std::cout<<"Khong tim thay nhan vien co ID = " << ID << std::endl;
    }
}

void DeleteEmployee(std::vector<std::shared_ptr<Employee>>& employees, int ID){
    for (size_t i = 0; i < employees.size(); i++){
        if(employees[i] -> getID()== ID){
            employees.erase(employees.begin() +i);
            Employee::CountEmployees--;
            break;
        }
    }
}

//Ham tim cac nhan vien Intern
std::vector<std::shared_ptr<Employee>> findAllInterns (const std::vector<std::shared_ptr<Employee>>& employees){
    std::vector<std::shared_ptr<Employee>> interns;
    
}




