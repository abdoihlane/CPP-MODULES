#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->GetIsSigned())
        throw AForm::GradeTooLowException();

    if (executor.GetGrade() > this->GetGradeToExecute())
        throw AForm::GradeTooLowException();

    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
        throw AForm::GradeTooLowException();
    
    file << "                                    " << std::endl;
    file << "                                 ^ " << std::endl;
    file << "                                /|\\ " << std::endl;
    file << "                               / | \\ " << std::endl;
    file << "                              /  |  \\ " << std::endl;
    file << "                             ^   ^   ^ " << std::endl;
    file << "                            /|\\  |  /|\\ " << std::endl;
    file << "                           / | \\ | / | \\ " << std::endl;
    file << "                          /  |  \\|/  |  \\ " << std::endl;
    file << "                         ^   ^   ^   ^   ^ " << std::endl;
    file << "                        /|\\  |  / \\  |  /|\\ " << std::endl;
    file << "                       / | \\ | /   \\ | / | \\ " << std::endl;
    file << "                      /  |  \\|/     \\|/  |  \\ " << std::endl;
    file << "                                 ||| " << std::endl;
    file << "                                 ||| " << std::endl;
    
    file.close();
}
