#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Error: wrong num of argumants.\n";
        return (-1);
    }
    if (check_brackets_and_decimal(av[1]))
        return (-1);
    std::stack<int> stack;
    int i = 0;
    int count = 0;
    int a, b, result;
    while (av[1][i])
    {
        while (av[1][i] && av[1][i] == ' ')
            i++;
        if (av[1][i] && check_num_operation(av[1][i]))
        {
            std::cout << "Error\n";
            return (-1);
        }
        if (isdigit(av[1][i]))
        {
            std::string num(1, av[1][i]);
            stack.push(atoi(num.c_str()));
            count++;
        }
        if (!is_operation(av[1][i]) && count <= 2)
        {
            count = 0;
            if (stack.size() < 2)
            {
                std::cout << "Error\n";
                return (-1);
            }
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            result = do_operation(a, b, av[1][i]);
            stack.push(result);
        }
        i++;
    }
    while (stack.empty() == false)
    {
        int t = stack.top();
        std::cout << "Result: " << t << "\n";
        stack.pop();
    }
}