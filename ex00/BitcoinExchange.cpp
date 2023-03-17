#include "BitcoinExchange.hpp"

int check_num(std::string value)
{
    for (size_t i = 0; i < value.size(); i++)
    {
        while (value[i] == ' ')
            i++;
        if (value[i] == '.' || value[i] == '-' || value[i] == '+')
            i++;
        if (!isdigit(value[i]))
        {
            std::cout << "Error: date or value is not a num\n";
            std::cout << value << "\n";
            return (0);
        }
    }
    return (1);
}

int check_value(int value)
{
    if (value > 1000)
    {
        std::cout << "Error: too large a number.\n";
        return (0);
    }
    else if (value < 0)
    {
        std::cout << "Error: not a positive number.\n";
        return (0);
    }
    return (1);
}

int check_date(int int_year, int int_month, int int_day)
{
    if ((int_year < 2009 || int_year > 2022) && (int_month < 1 || int_month > 12) && (int_day < 1 || int_day > 31))
    {
        std::cout << "Error bad date input " << "=> " << int_year << '-' << int_month << '-' << int_day << std::endl;
        return (0);
    }
    if (int_month == 2 && int_day > 29)
    {
        std::cout << "Error bad date input " << "=> " << int_year << '-' << int_month << '-' << int_day << std::endl;
        return (0);
    }
    return (1);
}

std::map<std::string,std::string>   create_a_map()
{
    std::map<std::string,std::string>   map;
    std::ifstream                       data("data.csv");
    size_t                              place;
    std::string                         line;

    getline(data, line);
    if (data.eof() == 1)
        exit (-1);
    while (data.eof() != 1) {
        getline(data, line);
        if (!line.empty())
        {
            place = line.find(',');
            map.insert(std::pair<std::string, std::string>(line.substr(0, place), line.substr(place + 1, line.size())));
        }
    }
    return (map);
}