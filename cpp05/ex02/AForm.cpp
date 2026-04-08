#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm& AForm::operator=(const AForm& other){
    if(this != &other){
        this->signedOrNot = other.signedOrNot;
    }
    return *this;
}

AForm::AForm(const AForm &other) : name(other.name), SignGrade(other.SignGrade), ExecuteGrade(other.ExecuteGrade) {
    this->signedOrNot = other.signedOrNot;
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string name, int SignGrade, int ExecuteGrade) : name(name), SignGrade(SignGrade), ExecuteGrade(ExecuteGrade) {
    if (SignGrade < 1 || ExecuteGrade < 1) 
            throw GradeTooHighException();
    else if (SignGrade > 150 || ExecuteGrade > 150) 
            throw GradeTooLowException();
    else 
        this->signedOrNot = false;
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::GetName(void) const {
    return name;
}

bool AForm::GetIsSigned(void) const {
    return signedOrNot;
}

int AForm::GetGradeToSign(void) const {
    return SignGrade;
}

int AForm::GetGradeToExecute(void) const {
    return ExecuteGrade;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.GetGrade() > SignGrade) 
        throw GradeTooLowException();
    else 
        this->signedOrNot = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!this->GetIsSigned())
        throw AForm::AFormNotSignedException();

    if (executor.GetGrade() > this->GetGradeToExecute())
        throw AForm::GradeTooLowException();
}

const char* AForm::AFormNotSignedException::what() const throw()
{
    return "AForm is not signed, cannot execute";
}