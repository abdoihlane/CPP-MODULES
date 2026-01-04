#include "ex01.h"
#include <string>
#include <iostream>
#include <iomanip> // for setw
#include <cstdlib> // for atoi

void add1(myclass *obj, int i)
{
    std::string line;

    std::cout << "\033[36mFIRST NAME : \033[0m";
    if(!getline(std::cin, line))
        exit(0);
    obj[i].firs_name = line;

    std::cout << "\033[36mLAST NAME : \033[0m";
    if(!getline(std::cin, line))
        exit(0);    
    obj[i].last_name = line;

    std::cout << "\033[33mNICKNAME : \033[0m";
    getline(std::cin, line);
    obj[i].nickname = line;

    std::cout << "\033[33mPHONE NUMBER : \033[0m";
    if(!getline(std::cin, line))
        exit(0);
    obj[i].phone_number = line;

    std::cout << "\033[31mDARKEST SECRET : \033[0m";
    if(!getline(std::cin, line))
        exit(0);
    obj[i].dark_secret = line;

    obj[i].index = i;
}

void search(myclass *obj)
{
    int i = 1;

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    while (i < 8 && obj[i].index != -1)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << obj[i].firs_name << "|"
                  << std::setw(10) << obj[i].last_name << "|"
                  << std::setw(10) << obj[i].nickname << std::endl;
        i++;
    }

    std::cout << "contact INDEX :" << std::endl;

    std::string line;
    if(!getline(std::cin, line))
        exit(0);

    i = std::atoi(line.c_str());

    if (i >= 1 && i <= 7)
    {
        std::cout << "first name : " << obj[i].firs_name << std::endl;
        std::cout << "last name : " << obj[i].last_name << std::endl;
        std::cout << "nickname : " << obj[i].nickname << std::endl;
        std::cout << "phone number : " << obj[i].phone_number << std::endl;
        std::cout << "darkest secret : " << obj[i].dark_secret << std::endl;
    }
}

int main(int ac, char **av)
{
    (void)av;

    myclass obj[8];
    for (int k = 0; k < 8; k++)
        obj[k].index = -1;

    if (ac < 1)
    {
        std::cout << "Error :" << std::endl;
    }
    else
    {
        int i = 1;
        std::string line;

        std::cout << "ENTER COMMAND :" << std::endl;

        while (getline(std::cin, line))
        {
            if (line == "ADD")
            {
                if (i == 8)
                    i = 1;
                add1(obj, i);
                i++;
            }
            else if (line == "SEARCH")
            {
                search(obj);
            }
            else if (line == "EXIT")
            {
                std::cout << "EXIT" << std::endl;
                return 0;
            }

            std::cout << "ENTER COMMAND :" << std::endl;
        }
    }
}
