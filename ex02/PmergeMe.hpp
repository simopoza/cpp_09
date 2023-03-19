#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

class PmergeMe
{
    std::vector<int> vec;
    std::vector<int>::iterator Vec_it;
    size_t begin;
    size_t end;
    
    public:
        PmergeMe(char *av[]);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        //member functions.
        void    check_args(char *av[]);//check positive integer.
        void    pushToVector(char *av[]);//fill the vec with ints.
        void    insertion_sort();
        void    merge_sort(size_t begin, size_t end);
        void    merge(size_t mid, size_t begin, size_t end);
        void    merge_insert();
        //exceptions.
        class Error : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif