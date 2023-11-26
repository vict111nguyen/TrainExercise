#pragma once
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"

class EmployeeManagement{
private: 
    std::vector<std::shared_ptr<Employee>> employees;
public:
    void AddEmployee(const std::shared_ptr<Employee> newEmployee);
    void EditEmployee(int ID, int EmpType);
    void DeleteEmployee(int ID);
    void FindAllInterns() const;
    void FindAllExperiences() const;
    void FindAllFreshers() const;
};
