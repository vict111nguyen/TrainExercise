#include <iostream>
#include "../headers/math_functions.h"
#include "../headers/other_functions.h"

int main() {
    int a = 5;
    int b = 3;
    int sum = add(a, b);
    int diff = substract(a, b);
    std::cout << "Sum: " << sum << std::endl;
    OtherFunctions::printMessage("Hello World");
    return 0;
}
