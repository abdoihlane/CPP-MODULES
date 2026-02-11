#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <ostream>


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

