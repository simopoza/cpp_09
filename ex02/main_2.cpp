#include "PmergeMe_2.hpp"

int main(int ac, char *av[])
{
    (void)ac;
    try
    {
        PmergeMe sorted(av);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}