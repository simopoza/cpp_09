#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <deque>

class PmergeMe
{
    std::vector<int> vec;
    std::vector<int>::iterator Vec_it;
    size_t vec_begin;
    size_t vec_end;
    clock_t vec_time;
    //deque.
    std::deque<int> deq;
    std::deque<int>::iterator deq_it;
    size_t deq_begin;
    size_t deq_end;
    clock_t deq_time;
    public:
        PmergeMe(char *av[]);
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        //member functions.
        void    check_args(char *av[]);//check positive integer.
        void    pushToVector(char *av[]);//fill the vec with ints.
        void    pushToDeque(char *av[]);//fill the deq with ints.
        //sort vec
        void    sort_vec();
        void    insertion_sort_vec();
        void    merge_sort_vec(size_t begin, size_t end);
        void    merge_vec(size_t mid, size_t begin, size_t end);
        //sort deq
        void    sort_deq();
        void    insertion_sort_deq();
        void    merge_sort_deq(size_t begin, size_t end);
        void    merge_deq(size_t mid, size_t begin, size_t end);
        //print vec sorted
        void    write_output_for_vec();
        //print deq sorted
        void    write_output_for_deq();
        //exceptions.
        class Error : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif