#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    std::ifstream    input(av[1]);
    std::ifstream    data("data.csv");

    if (!data.is_open())
    {
        std::cout << "Error: there is no .csv file.\n";
        return (-1);
    }
    if (ac != 2 || !input.is_open())
    {
        std::cout << "Error: could not open file.\n";
        return (-1);
    }
    Btc exchange_rate;
    exchange_rate.find_exchange_rate(av[1]);
}