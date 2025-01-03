#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 50);
        Bureaucrat highBureaucrat("Aris", 16);
        Form form("Tax Form", 75, 100);
        
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
        
        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        Form highForm("High Level Form", 25, 30);
        bureaucrat.signForm(highForm);
        std::cout << highForm << std::endl;
        highBureaucrat.signForm(highForm);
        std::cout << highForm << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception1: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid", 151, 100);
    } catch (std::exception& e) {
        std::cout << "Exception2: " << e.what() << std::endl;
    }

    return 0;
}