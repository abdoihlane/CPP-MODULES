#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void execute(Bureaucrat const & executor) const;
}; 

#endif
