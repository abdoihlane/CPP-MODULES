#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <ostream>
#include "AForm.hpp"
class AForm;
class PrisidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class Bureaucrat{
    private :
        const std::string name;
        int               grade;
    public :
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string GetName(void) const;
        int GetGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &f);
        void executeForm(AForm &f);
    class GradeTooHighException : public std::exception {
	    public:
		    virtual const char* what() const throw();
	};

    class GradeTooLowException : public std::exception {
    	public:
	    	virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif

