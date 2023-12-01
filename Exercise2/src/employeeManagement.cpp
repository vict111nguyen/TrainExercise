#include "../headers/employeeManager.h"
#include "../headers/validator.h"

std::vector<std::shared_ptr<Employee>> EmployeeManagement::getEmployee(){
    return employees;
}

void EmployeeManagement::AddEmployee(const std::shared_ptr<Employee> newEmployee){
    // Kiểm tra nếu ID đã tồn tại
    auto it = std::find_if(employees.begin(), employees.end(), [&newEmployee](const std::shared_ptr<Employee>& emp) {
                               return emp->getID() == newEmployee->getID();
                           });

    if (it != employees.end()) {
        *it = newEmployee;
    } else {
        employees.push_back(newEmployee);
    }

    // Employee::CountEmployees++;
}

void EmployeeManagement::EditEmployee(int ID){
    //Tìm nhan vien theo ID và dieu chinh thong tin
    //duyệt qua từng phần tử trong vector employees và mỗi phần tử được tham chiếu bởi biến tạm emp, cho phép ta thao tác trực tiếp với từng nhân viên trong danh sách employees.
    bool Found = false;
    for(const auto& emp : employees){
        if(emp -> getID() == ID){
            // Cho phép người dùng chỉnh sửa thông tin
            std::string newName, newBirthday, newPhone, newEmail;
            bool validInput = false;
            while(!validInput){
                try
                {
                    std::cout << "Enter new name: ";
                    getline(std::cin, newName); 
                    Validator::ValidateFullName(newName);
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
                    std::cout << "Enter new Date of birth: ";
                    getline(std::cin, newBirthday); 
                    Validator::ValidateBirthDay(newBirthday); 
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
                    std::cout << "Enter new Phone number: ";
                    getline(std::cin, newPhone); 
                    Validator::ValidatePhone(newPhone);
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
                    std::cout << "Enter new Email: ";
                    getline(std::cin, newEmail); 
                    Validator::ValidateEmail(newEmail);
                    validInput = true;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }  
            }

            //Experience
            if(emp ->getEmpType() == 0){
                //Thực hiện downcasting để sử dụng method cua lớp dẫn xuất Experience
                auto experience = std::dynamic_pointer_cast<Experience>(emp);
                int newExpInYear;
                std::string newProSkill;

                std::cout << "Enter new ProSkill: ";
                std::getline(std::cin, newProSkill);
                experience -> setProSkill(newProSkill);
                std::cout << "Enter new Experience in year: ";
                std::cin >> newExpInYear;
                experience -> setExpInYear(newExpInYear);
                // Hiển thị thông tin nhân viên sau khi chỉnh sửa
                std::cout << "Employee information after editing:" << std::endl;
                experience->showInfor();
            }

            //Fresher
            else if(emp ->getEmpType() == 1){
                auto fresher = std::dynamic_pointer_cast<Fresher>(emp);
                std::string newGraDate;
                std::string newGraRank;

                std::cout << "Enter new Graduation Date: ";
                std::getline(std::cin, newGraDate);
                Validator::ValidateBirthDay(newGraDate);
                fresher -> setGraDate(newGraDate);
                std::cout << "Enter new Graduation Rank: ";
                std::getline(std::cin, newGraRank);
                fresher -> setGraRank(newGraRank);
                // Hiển thị thông tin nhân viên sau khi chỉnh sửa
                std::cout << "Employee information after editing:" << std::endl;
                fresher->showInfor();
            }

            else if(emp ->getEmpType() == 2){
                auto intern = std::dynamic_pointer_cast<Intern>(emp);
                std::string newMajor;
                int newSemester;
                std::string newUniversityName;

                std::cout << "Enter new Graduation Date: ";
                std::getline(std::cin, newMajor);
                intern -> setMajor(newMajor);
                std::cout << "Enter new Graduation Rank: ";
                std::cin >> newSemester; std::cin.ignore();
                intern -> setSemester(newSemester);
                std::cout << "Enter new Graduation Rank: ";
                std::getline(std::cin, newUniversityName);
                intern -> setUniversityName(newUniversityName);
                // Hiển thị thông tin nhân viên sau khi chỉnh sửa
                std::cout << "Employee information after editing:" << std::endl;
                intern->showInfor();
            }
        

            // Hiển thị thông tin nhân viên sau khi chỉnh sửa
            
            Found = true;
            break;
        }
        if(!Found){
            std::cout<<"Khong tim thay nhan vien co ID = " << ID << std::endl;
        }
    }
}
void EmployeeManagement::DeleteEmployee(int ID){
    for (size_t i = 0; i < employees.size(); i++){
        if(employees[i] -> getID()== ID){
            employees.erase(employees.begin() +i);
            // Employee::CountEmployees--;
            break;
        }
    }
}

void EmployeeManagement::FindByID(int ID) const{
    for(const auto& emp : employees){
        if(emp -> getID() == ID){
            emp -> showInfor();
        }
    }
}

void EmployeeManagement::FindAllExperiences() const{
    std::cout << "All the Interns: " << std::endl;
    for(const auto& emp : employees){
        if(emp -> getEmpType() == 0){
            emp -> showInfor();
        }
    }
}
void EmployeeManagement::FindAllFreshers() const{
    std::cout << "All the Interns: " << std::endl;
    for(const auto& emp : employees){
        if(emp -> getEmpType() == 1){
            emp -> showInfor();
        }
    }
}
void EmployeeManagement::FindAllInterns() const{
    std::cout << "All the Interns: " << std::endl;
    for(const auto& emp : employees){
        if(emp -> getEmpType() == 2){
            emp -> showInfor();
        }
    }
}


