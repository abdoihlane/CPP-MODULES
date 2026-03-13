#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// Intern::Intern(const Intern &other) {
//     std::cout << "Intern copy constructor called" << std::endl;
// }

// Intern& Intern::operator=(const Intern& other) {
//     if(this != &other) {
//         // No member variables to copy
//     }
//     std::cout << "Intern assignment operator called" << std::endl;
//     return *this;
// }

// AForm* Intern::makeForm(std::string formName, std::string target) {
//     if (formName == "PresidentialPardonForm") {
//         return new PresidentialPardonForm(target);
//     } else if (formName == "RobotomyRequestForm") {
//         return new RobotomyRequestForm(target);
//     } else if (formName == "ShrubberyCreationForm") {
//         return new ShrubberyCreationForm(target);
//     } else {
//         std::cout << "Intern cannot create form: " << formName << std::endl;
//         return nullptr;
//     }
// }

AForm* Intern::makeForm(std::string formname, std::string target)
{
    std::string forms[3] = {
        "Presidential request",
        "Robotomy request",
        "Shrubbery request"
    };

    int index = -1;

    for (int i = 0; i < 3; i++)
    {
        if (formname == forms[i])
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
        case 0:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);

        case 1:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);

        case 2:
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(target);

        default:
            std::cout << "Intern cannot create form: " << formname << std::endl;
            return NULL;
    }
}
