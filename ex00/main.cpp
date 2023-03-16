#include "BitcoinExchange.hpp"

void    find_exchange_rate(std::string line, std::map<std::string,std::string> map, std::map<std::string, std::string>::iterator it)
{
    std::string year;
    std::string month;
    std::string day;
    std::string date;
    std::string value;
    std::string size;
    size_t      index;
    size_t second;
    
    index = line.find('|');
    date = line.substr(0, index-1);
    value = line.substr(index + 1, line.size());
    if (!check_num(value))
        return ;
    int i = 0;
    while (value.size() && value[i] == ' ')
        i++;
    std::string num = value.substr(i, value.size());
    std::string range = "2147483648";
    if (num >= range)
    {
        std::cout << "Error: too large a number.\n";
        return ;
    }
    int int_value = atoi(value.c_str());
    if (!check_value(int_value))
        return ;
    index = date.find('-');
    year = date.substr(0,  index);
    if (!check_num(year))
        return ;
    int int_year = atoi(year.c_str());
    size = date.substr(index + 1, date.size());
    second = size.find('-');
    month = size.substr(0, second);
    if (!check_num(month))
        return ;
    int int_month = atoi(month.c_str());
    day = size.substr(second + 1, date.size());
    if (!check_num(day))
        return ;
    int int_day = atoi(day.c_str());
    if (!check_date(int_year, int_month, int_day))
        return ;
    float exchange_rate;
    while (it != map.end())
    {
        std::string B_year = it->first.substr(0, 4);
        if (year == B_year)
        {
            std::string B_month = it->first.substr(5, 2);
            if (month == B_month)
            {
                std::string B_day = it->first.substr(8, 2);
                if (day == B_day || day < B_day)
                {
                    std::cout << date << " => " << value << " = " << int_value * exchange_rate << std::endl;
                    return ;
                }
                exchange_rate = std::stof(it->second);
            }
        }
        it++;
    }
}

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
    std::map<std::string,std::string>   map = create_a_map();
    std::map<std::string, std::string>::iterator it = map.begin();
    size_t place;
    std::string line;
    getline(input, line);
    while (!input.eof())
    {
        getline(input, line);
        if (!line.empty())
        {
            place = line.find('|');
            if (place == std::string::npos)
                std::cout << "Error: bad input => " << line.substr(0, line.size()) << std::endl;
            else
                find_exchange_rate(line, map, it);
        }
    }
}
