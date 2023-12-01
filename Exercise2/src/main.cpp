#include "../headers/validator.h"
#include "../headers/certificate.h"
#include "../headers/employee.h"
#include "../headers/experience.h"
#include "../headers/fresher.h"
#include "../headers/intern.h"
#include "../headers/employeeManager.h"


int main(){
    EmployeeManagement Employees;
    while(true){
        std::cout << "--------------------------------" << std::endl;
        std::cout <<"Choose type of action do you want?" <<std::endl;
        std::cout <<"1. Add Employee. \n";
        std::cout <<"2. Edit Employee.\n";
        std::cout <<"3. Delete Employee.\n";
        std::cout <<"4. Find.\n";
        std::cout <<"5. Display Information.\n";
        std::cout <<"0. Exit.\n";
        std::cout <<"Enter your choice (0, 1, 2, 3, 4, 5): ";

        std::shared_ptr<Employee> newEmployee = nullptr;
        int choice;
        int ID;
        std::cin >> choice;
        if(choice == 0){
            break;
        }
        switch (choice){
            case 1: 
                std::cout << "--------------------------------" << std::endl;
                std::cout << "You want to add: \n";
                std::cout << "0. An Experience\n";
                std::cout << "1. A Fresher\n";
                std::cout << "2. An Intern\n";
                std::cout << "Choose which type employee you want to add (0, 1, 2): ";
                int Emp_choice;
                std::cin >> Emp_choice;
                
                switch (Emp_choice){
                    case 0:
                        newEmployee = std::make_shared<Experience>();
                        Employees.AddEmployee(newEmployee);
                        break;
                    case 1: 
                        newEmployee = std::make_shared<Fresher>();
                        Employees.AddEmployee(newEmployee);
                        break;
                    case 2:
                        newEmployee = std::make_shared<Intern>();
                        Employees.AddEmployee(newEmployee);
                        break;
                    default:
                        std::cout << "\nInvalid choice. Enter again!";
                        continue; 
                }
                break;
            case 2:
                std::cout << "Enter ID you want to edit: "; std::cin >> ID;
                Employees.EditEmployee(ID);
                break;
            case 3:
                std::cout << "Enter ID you want to delete: "; std::cin >> ID;
                Employees.DeleteEmployee(ID);
                break;
            case 4: 
                std::cout << "--------------------------------" << std::endl;
                std::cout << "0. Find by ID. \n";
                std::cout << "1. Find all Experiences. " << std::endl;
                std::cout << "2. Find all Freshers. " << std::endl;
                std::cout << "3. Find all Interns. " << std::endl;
                std::cout << "Enter your choice: ";
                int  find_choice; 
                std::cin >> find_choice;
                switch (find_choice)
                {
                    case 0:
                        std::cin >> ID;
                        Employees.FindByID(ID);
                        break;
                    case 1:
                        Employees.FindAllExperiences();
                        break;
                    case 2: 
                        Employees.FindAllFreshers();
                        break;
                    case 3:
                        Employees.FindAllInterns();
                        break;
                    default:
                        std::cout << "\nInvalid choice. Enter again!";
                        continue;
                }
                break;
            case 5:
                std::cout << "--------------------------------" << std::endl;
                std::cout << "All the employees: " << std::endl;
                for (const auto& emp: Employees.getEmployee()){
                    emp -> showInfor();
                }
                break;
            default:
                std::cout << "\nInvalid choice. Enter again!";
                continue;

        }
    }
    return 0;
}





