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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.GetName() << ", Bureaucrat grade " << b.GetGrade() << ".";
    return out;
}

void Bureaucrat::incrementGrade(void) {
    if (grade - 1 < 1) 
        throw GradeTooHighException();
    else 
        grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (grade + 1 > 150) 
        throw GradeTooLowException();
    else 
        grade++;
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.GetName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << f.GetName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &f) {
    try {
        f.execute(*this);
        std::cout << name << " executed " << f.GetName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't execute " << f.GetName() << " because " << e.what() << std::endl;
    }
}
