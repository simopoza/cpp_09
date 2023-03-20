#include "BitcoinExchange.hpp"

Btc::Btc()
{
    std::ifstream   data("data.csv");
    std::string     line;
    size_t          place;

    getline(data, line);
    if (data.eof() == 1)
        exit (-1);
    while (data.eof() != 1)
    {
        getline(data, line);
        if (!line.empty())
        {
            place = line.find(',');
            this->map.insert(std::pair<std::string, std::string>(line.substr(0, place), line.substr(place + 1, line.size())));
        }
    }
}

Btc::Btc(const Btc& obj)
{
    this->map = obj.map;
}

Btc&    Btc::operator=(const Btc& obj)
{
    this->map = obj.map;
    return (*this);
}

Btc::~Btc()
{
}

int    Btc::check_errors(std::string date, std::string value)
{
    std::string year;
    std::string month;
    std::string day;
    std::string size;
    size_t      index;
    size_t second;
    
    if (!check_num(value))
        return -1;
    double int_value;
    std::stringstream convert;
    convert << value;
    convert >> int_value;
    if (!check_value(int_value))
        return -1;
    index = date.find('-');
    year = date.substr(0,  index);
    if (!check_num(year))
        return -1;
    int int_year = atoi(year.c_str());
    size = date.substr(index + 1, date.size());
    second = size.find('-');
    month = size.substr(0, second);
    if (!check_num(month))
        return -1;
    int int_month = atoi(month.c_str());
    day = size.substr(second + 1, date.size());
    if (!check_num(day))
        return -1;
    int int_day = atoi(day.c_str());
    if (!check_date(int_year, int_month, int_day, date))
        return -1;
    return (0);
}

void    Btc::do_it(std::string line)
{
    std::string date;
    std::string value;
    size_t      index;

    index = line.find('|');
    date = line.substr(0, index - 1);
    value = line.substr(index + 1, line.size());
    if (check_errors(date, value) == -1)
        return ;
    float   exchange_rate;
    this->it = this->map.lower_bound(date);
    this->it--;
    exchange_rate = atof(it->second.c_str());
    std::cout << date << " => " << value << " = " << atoi(value.c_str()) * exchange_rate << std::endl;
}

void    Btc::find_exchange_rate(char *av)
{
    std::ifstream    input(av);
    std::string line;
    size_t place;

    while (!input.eof())
    {
        getline(input, line);
        if (!line.empty())
        {
            place = line.find('|');
            if (place == std::string::npos)
                std::cout << "Error: bad input => " << line.substr(0, line.size()) << std::endl;
            else
                do_it(line);
        }
    }
}

int Btc::check_num(std::string value)
{
    for (size_t i = 0; i < value.size(); i++)
    {
        while (value[i] == ' ')
            i++;
        if (value[i] == '.' || value[i] == ',' || value[i] == '-' || value[i] == '+')
            i++;
        if (!isdigit(value[i]))
        {
            std::cout << "Error: date or value is not a num ";
            std::cout << value << "\n";
            return (0);
        }
    }
    return (1);
}

int Btc::check_value(double value)
{
    if (value > 1000)
    {
        std::cout << "Error: too large a number.\n";
        return (0);
    }
    if (value < 0)
    {
        std::cout << "Error: not a positive number.\n";
        return (0);
    }
    return (1);
}

int Btc::check_date(int int_year, int int_month, int int_day, std::string date)
{
    if ((int_year < 2009 || int_year > 2022) || (int_month < 1 || int_month > 12) || (int_day < 1 || int_day > 31))
    {
        std::cout << "Error bad date input " << "=> " << date << std::endl;
        return (0);
    }
    if (int_month == 2 && int_day > 29)
    {
        std::cout << "Error bad date input " << "=> " << int_year << '-' << int_month << '-' << int_day << std::endl;
        return (0);
    }
    return (1);
}