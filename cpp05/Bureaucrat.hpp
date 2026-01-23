#include <string>
#include <iostream>

class bureaucrat{
    private :
        const std::string name;
        int               grade;
    public :
        bureaucrat();
        bureaucrat(std::string name, int grade);
        bureaucrat(std::string name);
        bureaucrat(int grade);
        ~bureaucrat();
        std::string GetName(void) const;
        void SetName(std::string _name);
        void GradeTooHighException();
        void GradeTooLowException();
};  