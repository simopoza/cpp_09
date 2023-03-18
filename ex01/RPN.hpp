#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    std::stack<double> stack;
    public:
        RPN(char *av);
        RPN(const RPN& obj);
        RPN&    operator=(const RPN& obj);
        ~RPN();
        //member functions.
        void    check_brackets_and_decimal(char *av);
        void    check_num_operation(char c);
        int     is_operation(char c);
        double  do_operation(int a, double b, char c);
        //exception
        class NO_VALID_RPN : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif