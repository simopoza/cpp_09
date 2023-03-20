#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Error.\n";
        return (-1);
    }
    try
    {
        RPN rpn(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}