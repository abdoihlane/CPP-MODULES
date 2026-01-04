#include <iostream>

void to_uppercase(char *sa)
{
    int i =0;
    while(sa[i])
    {
        if(sa[i] >= 'a' && sa[i] <= 'z')
            sa[i] = sa[i] - 32;
        i++;
    }
}

int main(int ac, char **av)
{
    int i =1;
    if(ac == 1)
        {
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
            return 0;
        }
    else
    {
        while(av[i])
            {
                to_uppercase(av[i]);
                 std::cout << av[i] << " ";
                i++;
            }
             std::cout <<  std::endl;
    }
    return 0;
}