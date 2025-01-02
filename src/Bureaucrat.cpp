#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& otherBureaucrat) : 
    _name(otherBureaucrat._name), _grade(otherBureaucrat._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& otherBureaucrat) {
    if (this != &otherBureaucrat) {
        _grade = otherBureaucrat._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}