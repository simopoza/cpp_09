#include "RPN.hpp"

RPN::RPN(char *av)
{
    check_brackets_and_decimal(av);
    int i, count, digit, operation;

    i = 0;
    count = 0;
    digit = 0;
    operation = 0;
    while (av[i])
    {
        while (av[i] && av[i] == ' ')
            i++;
        if (!av[i])
            break ;
        check_num_operation(av[i]);
        if (isdigit(av[i]))
        {
            std::string num(1, av[i]);
            this->stack.push(atoi(num.c_str()));
            count++;
            digit++;
        }
        else
        {
            count = 0;
            if (this->stack.size() < 2)
                throw NO_VALID_RPN();
            operations(av[i]);
            operation++;
        }
        i++;
    }
    if (digit - 1 != operation)
        throw NO_VALID_RPN();
}

void    RPN::operations(char c)
{
    double a, b, result;

    a = this->stack.top();
    this->stack.pop();
    b = this->stack.top();
    this->stack.pop();
    result = do_operation(a, b, c);
    this->stack.push(result);
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

double RPN::do_operation(int a, double b, char c)
{
    std::cout << "a is : " << a << "b is : " << b << "\n";
    if (c == '*')
        return (b * a);
    if (c == '/')
    {
        if (a >= 1)
            return (b / a);
        throw NO_VALID_RPN();
    }
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

    if (this->stack.empty() == false)
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