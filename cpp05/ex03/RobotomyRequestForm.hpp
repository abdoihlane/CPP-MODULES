#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    void execute(Bureaucrat const & executor) const;
}; 

#endif
