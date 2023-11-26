#pragma once
#include <iostream>
#include <regex>
#include <stdexcept>
#include "Exception"

class Validator {
public:
    static void ValidateFullName(const std::string& fullName);
    static void ValidateBirthDay(const std::string& birthDay);
    static void ValidatePhone(const std::string& phoneNumber);
    static void ValidateEmail(const std::string& email);
};
