#include "validator.h"

void Validator::ValidateFullName(const std::string& fullName){
    std::regex pattern("[a-zA-Z]+");
    if(!std::regex_match(fullName, pattern)){
        throw std::invalid_argument("Invalid fullName!");
    }
} 
void Validator::ValidateBirthDay(const std::string& birthDay){
    std::regex pattern("\\d{4}-\\d{2}-\\d{2}");
    if(!std::regex_match(birthDay, pattern)){
        throw std::invalid_argument("Invalid Birthday!");
    }
} 
void Validator::ValidatePhone(const std::string& phoneNumber){
    std::regex pattern("\\d{10}");
    if(!std::regex_match(phoneNumber, pattern)){
        throw std::invalid_argument("Invalid phone Number!");
    }
} 
void Validator::ValidateEmail(const std::string& email){
    std::regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    if(!std::regex_match(email, pattern)){
        throw std::invalid_argument("Invalid Email!");
    }
} 


