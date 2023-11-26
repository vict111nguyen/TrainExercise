#include "validator.h"
#include "certificate.h"
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include "employeeManager.h"


int main(){
    EmployeeManagement Employees;

    std::shared_ptr<Experience> Experience1 = std::make_shared<Experience>(1, "Nguyen Van A", "11/11/2000", "0987765674", "123@gmail.com", 2, "C#");
    std::shared_ptr<Fresher> Fresher1 = std::make_shared<Fresher>(2,"Nguyen Van A", "27/07/1992", "0378998873", "456@gmai.com", "11/5/2023", "Good");
    std::shared_ptr<Intern> Intern1 = std::make_shared<Intern>(3, "Nguyen TRan C", "1/11/1999", "0945678999", "789@gmail.com", "IT", 5, "Hust"); 
    
    Employees.AddEmployee(Experience1);
    Employees.AddEmployee(Fresher1);
    Employees.AddEmployee(Intern1);

    Employees.FindAllExperiences();
    Employees.FindAllFreshers();
    Employees.FindAllInterns();
    Experience1 -> showInfor();
    
    Employees.DeleteEmployee(2);
    Employees.EditEmployee(1, 2);


    return 0;
}





