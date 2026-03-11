#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    // std::cout << "========== Testing PresidentialPardonForm ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b1("Alice", 5);
    //     std::cout << b1 << std::endl;
        
    //     PresidentialPardonForm form1("Bob");
    //     std::cout << "Created form for " << form1.GetName() << std::endl;
        
    //     b1.signForm(form1);
    //     b1.executeForm(form1);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "\n========== Testing unsigned PresidentialPardonForm ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b2("Charlie", 5);
    //     PresidentialPardonForm form2("David");
    //     b2.executeForm(form2);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "\n========== Testing RobotomyRequestForm ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b3("Eve", 45);
    //     std::cout << b3 << std::endl;
        
    //     RobotomyRequestForm form3("Frank");
    //     std::cout << "Created form for " << form3.GetName() << std::endl;
        
    //     b3.signForm(form3);
    //     for (int i = 0; i < 3; i++) {
    //         std::cout << "\nAttempt " << (i + 1) << ":" << std::endl;
    //         b3.executeForm(form3);
    //     }
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "\n========== Testing RobotomyRequestForm with insufficient grade ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b4("Grace", 150);
    //     RobotomyRequestForm form4("Henry");
    //     b4.signForm(form4);
    //     b4.executeForm(form4);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "\n========== Testing ShrubberyCreationForm ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b5("Iris", 137);
    //     std::cout << b5 << std::endl;
        
    //     ShrubberyCreationForm form5("Garden");
    //     std::cout << "Created form for " << form5.GetName() << std::endl;
        
    //     b5.signForm(form5);
    //     b5.executeForm(form5);
    //     std::cout << "Shrubbery created in Garden_shrubbery file" << std::endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    
    // std::cout << "\n========== Testing ShrubberyCreationForm with insufficient grade ==========" << std::endl;
    // try
    // {
    //     Bureaucrat b6("Jack", 150);
    //     ShrubberyCreationForm form6("Park");
    //     b6.signForm(form6);
        b6.executeForm(form6);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    try{
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        // delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
