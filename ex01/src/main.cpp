#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat normal("Normal", 75);
        std::cout << normal << std::endl;

        normal.incrementGrade();
        std::cout << "After increment: " << normal << std::endl;

        normal.decrementGrade();
        std::cout << "After decrement: " << normal << std::endl;

        Bureaucrat tooHigh{"TooHigh", 0};
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow{"TooLow", 151};
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}