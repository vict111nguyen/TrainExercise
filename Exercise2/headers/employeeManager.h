#pragma once
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"

class EmployeeManagement{
private: 
    std::vector<std::shared_ptr<Employee>> employees;
public:
    std::vector<std::shared_ptr<Employee>> getEmployee();
    void AddEmployee(const std::shared_ptr<Employee> newEmployee);
    void EditEmployee(int ID);
    void DeleteEmployee(int ID);
    void FindAllInterns() const;
    void FindAllExperiences() const;
    void FindAllFreshers() const;
    void FindByID(int ID) const;
};
