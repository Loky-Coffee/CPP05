#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 50);
        Form form("Tax Form", 75, 100);
        
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
        
        bureaucrat.signForm(form);
        std::cout << form << std::endl;

        Form highForm("High Level Form", 25, 30);
        bureaucrat.signForm(highForm);

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid", 151, 100);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}