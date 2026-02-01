#include "Bureaucrat.hpp"

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if(this != &other){
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < 1) 
            throw GradeTooHighException();
    else if (grade > 150) 
            throw GradeTooLowException();
    else 
        this->grade = grade;
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::GetName(void) const {
    return name;
}

int Bureaucrat::GetGrade(void) const {
    return grade;
}

const char *Bureaucrat::GradeTooHighException() {
    return "Grade is too hight! Must be between 1 and 150.";    
}

const char *Bureaucrat::GradeTooLowException() {
    return "Grade is too low! Must be between 1 and 150.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.GetName() << ", Bureaucrat grade " << b.GetGrade() << ".";
    return out;
}