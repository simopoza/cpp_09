#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class Btc
{
    std::map<std::string,std::string>   map;
    std::map<std::string, std::string>::iterator it;
    public:
        Btc();
        Btc(const Btc& obj);
        Btc&    operator=(const Btc& obj);
        ~Btc();
        //member functions.
        void    find_exchange_rate(char *av);
        int     check_errors(std::string date, std::string value);
        int     check_num(std::string value);
        int     check_value(double value);
        int     check_date(int int_year, int int_month, int int_day, std::string date);
        void    do_it(std::string line);
};

#endif