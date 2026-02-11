#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
class Form
{
private:
    const std::string name;
    bool signedOrNot;
    const int SignGrade;
    const int ExecuteGrade;
public:
    Form();
    Form(const Form &other);
    Form(std::string name, int SignGrade, int ExecuteGrade);
    ~Form();
    Form& operator=(const Form& other);
    std::string GetName(void) const;
    bool GetIsSigned(void) const;
    int GetGradeToSign(void) const;
    int GetGradeToExecute(void) const;
    void beSigned(const Bureaucrat &b);
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};


#endif