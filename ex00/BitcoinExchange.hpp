#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

int check_num(std::string value);
int check_value(int value);
int check_date(int int_year, int int_month, int int_day);
std::map<std::string,std::string>   create_a_map();

#endif