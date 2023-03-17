#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

int check_brackets_and_decimal(char *av);
int check_num_operation(char c);
int is_operation(char c);
int do_operation(int a, int b, char c);

#endif