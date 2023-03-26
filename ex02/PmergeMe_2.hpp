#ifndef PMERGEME_2_HPP
#define PMERGEME_2_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <deque>

class PmergeMe
{
    std::vector<int> vec;
    std::vector<int>::iterator Vec_it;

    public:
        PmergeMe(char *av[]);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        //member functions.
        void    check_args(char *av[]);//check positive integer.
        void    pushToVector(char *av[]);//fill the vec with ints.
        void    merge_insertion();
        //exceptions.
        class Error : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif