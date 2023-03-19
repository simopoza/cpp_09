#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char *av[])
{
    check_args(av);
    pushToVector(av);
    this->begin = 0;
    this->end = vec.size() - 1;
    this->merge_insert();
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    this->vec = obj.vec;
    this->Vec_it = obj.Vec_it;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    this->vec = obj.vec;
    this->Vec_it = obj.Vec_it;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    this->Vec_it = vec.begin();
    while (this->Vec_it != this->vec.end())
    {
        std::cout << (*this->Vec_it) << ' ';
        this->Vec_it++;
    }
}

void    PmergeMe::check_args(char *av[])
{
    for (int i = 1; av[i]; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            if (isdigit(av[i][j]) || av[i][j] == ' ')
                continue;
            else
                throw Error();
        }
    }
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error\n");
}

void    PmergeMe::pushToVector(char *av[])
{
    for (int i = 1; av[i]; i++)
    {
        std::string str;
        std::stringstream   s(av[i]);
        while (s >> str)
            vec.push_back(atoi(str.c_str()));
    }
}

void    PmergeMe::insertion_sort()
{
    size_t len = vec.size();
    size_t     j;

    for (size_t i = 1; i <= len - 1; i++)
    {
        j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            std::swap(vec[j], vec[j - 1]);
            j = j - 1;
        }
    }
}

void    PmergeMe::merge(size_t mid, size_t begin, size_t end)
{
    size_t IndexsubOne = 0;
    size_t IndexsubTwo = 0;
    size_t  subOne = mid - begin + 1;
    size_t  subTwo = end - mid;
    std::vector<int> Left_vec;
    std::vector<int> Right_vec;
    Left_vec.resize(subOne);
    Right_vec.resize(subTwo);

    for (size_t i = 0; i < subOne; i++)
        Left_vec[i] = this->vec[begin + i];
    for (size_t j = 0; j < subTwo; j++)
        Right_vec[j] = this->vec[mid + 1 + j];
    size_t Index_left = begin;
    while (IndexsubOne < subOne && IndexsubTwo < subTwo)
    {
        if (Left_vec[IndexsubOne] <= Right_vec[IndexsubTwo])
            this->vec[Index_left] = Left_vec[IndexsubOne++];
        else
            this->vec[Index_left] = Right_vec[IndexsubTwo++];
        Index_left++;
    }
    while (IndexsubOne < subOne)
        this->vec[Index_left++] = Left_vec[IndexsubOne++];
    while (IndexsubTwo < subTwo)
        this->vec[Index_left++] = Right_vec[IndexsubTwo++];
}

void    PmergeMe::merge_sort(size_t begin, size_t end)
{
    if (begin >= end)
        return ;
    size_t mid = begin + (end - begin) / 2;
    merge_sort(begin, mid);
    merge_sort(mid + 1, end);
    merge(mid, begin, end);
}

void    PmergeMe::merge_insert()
{

}