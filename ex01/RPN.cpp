#include "RPN.hpp"

int check_brackets_and_decimal(char *av)
{
    int i = 0;
    while(av[i])
    {
        if (av[i] == '(' || av[i] == ')' || av[i] == '.')
        {
            std::cout << "Error\n";
            return (-1);
        }
        i++;
    }
    return (0);
}

int check_num_operation(char c)
{
    if (isdigit(c) || (c == '/' || c == '-' || c == '+' || c == '*'))
        return (0);
    return (-1);
}

int is_operation(char c)
{
    if (c == '/' || c == '-' || c == '+' || c == '*')
        return (0);
    return (-1);
}

int do_operation(int a, int b, char c)
{
    if (c == '*')
        return (b * a);
    if (c == '/')
        return (b / a);
    if (c == '-')
        return (b - a);
    return (a + b);
}
