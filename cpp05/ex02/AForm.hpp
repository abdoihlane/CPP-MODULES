#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat; 
class AForm
{
private:
    const std::string name;
    bool signedOrNot;
    const int SignGrade;
    const int ExecuteGrade;
public:
    AForm();
    AForm(const AForm &other);
    AForm(std::string name, int SignGrade, int ExecuteGrade);
    ~AForm();
    AForm& operator=(const AForm& other);
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