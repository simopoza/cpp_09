#include "RPN.hpp"

RPN::RPN(char *av)
{
    check_brackets_and_decimal(av);
    int i = 0;
    int count = 0;
    double a, b, result;

    while (av[i])
    {
        while (av[i] && av[i] == ' ')
            i++;
        check_num_operation(av[i]);
        if (isdigit(av[i]))
        {
            std::string num(1, av[i]);
            stack.push(atoi(num.c_str()));
            count++;
        }
        if (!is_operation(av[i]) && count <= 2)
        {
            count = 0;
            if (stack.size() < 2)
                throw NO_VALID_RPN();
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            result = do_operation(a, b, av[i]);
            stack.push(result);
        }
        i++;
    }
}

void    RPN::check_brackets_and_decimal(char *av)
{
    int i = 0;
    while(av[i])
    {
        if (av[i] == '(' || av[i] == ')' || av[i] == '.')
            throw NO_VALID_RPN();
        i++;
    }
}

void    RPN::check_num_operation(char c)
{
    if (isdigit(c) || (c == '/' || c == '-' || c == '+' || c == '*'))
        return ;
    throw NO_VALID_RPN();
}

int RPN::is_operation(char c)
{
    if (c == '/' || c == '-' || c == '+' || c == '*')
        return (0);
    return (-1);
}

double RPN::do_operation(int a, double b, char c)
{
    if (c == '*')
        return (b * a);
    if (c == '/')
        return (b / a);
    if (c == '-')
        return (b - a);
    return (a + b);
}

RPN::RPN(const RPN& obj)
{
    this->stack = obj.stack;
}

RPN&    RPN::operator=(const RPN& obj)
{
    this->stack = obj.stack;
    return (*this);
}

RPN::~RPN()
{
    double t;

    while (this->stack.empty() == false)
    {
        t = this->stack.top();
        std::cout << "Result: " << t << "\n";
        this->stack.pop();
    }
}

const char *RPN::NO_VALID_RPN::what() const throw()
{
    return ("Error\n");
}