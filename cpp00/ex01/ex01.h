#ifndef EX01_H
#define EX01_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sstream> 
#include <iomanip>
#include <cstdlib>

using namespace std;

class Contact
{
public:
    Contact() : index(-1) {}
    void setFields(const std::string &first, const std::string &last,
                   const std::string &nick, const std::string &phone,
                   const std::string &secret, int idx)
    {
        first_name = first;
        last_name = last;
        nickname = nick;
        phone_number = phone;
        dark_secret = secret;
        index = idx;
    }

    void printSummary() const
    {
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << truncateField(first_name) << "|"
                  << std::setw(10) << truncateField(last_name) << "|"
                  << std::setw(10) << truncateField(nickname) << "\n";
    }

    void printDetails() const
    {
        std::cout << "First name: " << first_name << "\n";
        std::cout << "Last name: " << last_name << "\n";
        std::cout << "Nickname: " << nickname << "\n";
        std::cout << "Phone number: " << phone_number << "\n";
        std::cout << "Darkest secret: " << dark_secret << "\n";
    }

    int getIndex() const { return index; }

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string dark_secret;
    int index;

    static std::string truncateField(const std::string &s)
    {
        if (s.length() <= 10)
            return s;
        std::string t = s.substr(0, 9);
        t += ".";
        return t;
    }
};

class myclass{
    public :
    string nickname;
    string last_name;
    string firs_name;
    string phone_number;
    string dark_secret;
    int index;
};
#endif