#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
    _name("default"), 
    _isSigned(false), 
    _gradeToSign(150), 
    _gradeToExecute(150) {
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : 
    _name(name), 
    _isSigned(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& otherForm) : 
    _name(otherForm._name),
    _isSigned(otherForm._isSigned),
    _gradeToSign(otherForm._gradeToSign),
    _gradeToExecute(otherForm._gradeToExecute) {
}

Form& Form::operator=(const Form& otherForm) {
    if (this != &otherForm) {
        _isSigned = otherForm._isSigned;
    }
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << ", signing grade " << form.getGradeToSign()
       << ", execution grade " << form.getGradeToExecute()
       << ", signed status: " << (form.getIsSigned() ? "signed" : "not signed");
    return os;
}
