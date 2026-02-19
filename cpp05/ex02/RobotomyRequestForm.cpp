#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->GetIsSigned())
        throw AForm::GradeTooLowException();

    if (executor.GetGrade() > this->GetGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0) {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << this->target << " robotomy failed." << std::endl;
    }
}
