#include "Form.hpp"
#include "Bureaucrat.hpp"

Form& Form::operator=(const Form& other){
    if(this != &other){
        this->signedOrNot = other.signedOrNot;
    }
    return *this;
}

Form::Form(const Form &other) : name(other.name), SignGrade(other.SignGrade), ExecuteGrade(other.ExecuteGrade) {
    this->signedOrNot = other.signedOrNot;
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string name, int SignGrade, int ExecuteGrade) : name(name), SignGrade(SignGrade), ExecuteGrade(ExecuteGrade) {
    if (SignGrade < 1 || ExecuteGrade < 1) 
            throw GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150) 
            throw GradeTooLowException();
    else 
        this->signedOrNot = false;
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::GetName(void) const {
    return name;
}

bool Form::GetIsSigned(void) const {
    return signedOrNot;
}

int Form::GetGradeToSign(void) const {
    return SignGrade;
}

int Form::GetGradeToExecute(void) const {
    return ExecuteGrade;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.GetGrade() > SignGrade) 
        throw GradeTooLowException();
    else 
        this->signedOrNot = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

