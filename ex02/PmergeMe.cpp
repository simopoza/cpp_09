#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char *av[])
{
    check_args(av);
    pushToVector(av);
    pushToDeque(av);
    sort_vec();
    sort_deq();
}

void    PmergeMe::sort_vec()
{
    std::cout << "Before: ";
    this->Vec_it = this->vec.begin();
    while (this->Vec_it != this->vec.end())
    {
        std::cout << (*this->Vec_it) << ' ';
        this->Vec_it++;
    }
    std::cout << std::endl;
    this->vec_begin = 0;
    this->vec_end = vec.size() - 1;
    clock_t vec_start = clock();
    this->merge_sort_vec(vec_begin, vec_end);
    this->vec_time = clock() - vec_start;
}

void    PmergeMe::sort_deq()
{
    this->deq_begin = 0;
    this->deq_end = deq.size() - 1;
    clock_t deq_start = clock();
    this->merge_sort_deq(deq_begin, deq_end);
    this->deq_time = clock() - deq_start;
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

void    PmergeMe::write_output_for_vec()
{
    this->Vec_it = this->vec.begin();
    std::cout << "After: ";
    while (this->Vec_it != this->vec.end())
    {
        std::cout << (*this->Vec_it) << ' ';
        this->Vec_it++;
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector : " << (float)this->vec_time/CLOCKS_PER_SEC << std::endl;
}

void    PmergeMe::write_output_for_deq()
{
    std::cout << "Time to process a range of " << this->deq.size() << " elements with std::deque : " << (float)this->deq_time/CLOCKS_PER_SEC << std::endl;
}

PmergeMe::~PmergeMe()
{
    write_output_for_vec();
    write_output_for_deq();
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
            this->vec.push_back(atoi(str.c_str()));
    }
}

void    PmergeMe::pushToDeque(char *av[])
{
    for (int i = 1; av[i]; i++)
    {
        std::string str;
        std::stringstream   s(av[i]);
        while (s >> str)
            this->deq.push_back(atoi(str.c_str()));
    }
}

void    PmergeMe::insertion_sort_vec()
{
    size_t len = this->vec.size();
    size_t     j;

    for (size_t i = 1; i <= len - 1; i++)
    {
        j = i;
        while (j > 0 && this->vec[j - 1] > this->vec[j])
        {
            std::swap(this->vec[j], this->vec[j - 1]);
            j = j - 1;
        }
    }
}

void    PmergeMe::merge_vec(size_t mid, size_t begin, size_t end)
{
    std::vector<int> Left_vec;
    std::vector<int> Right_vec;
    size_t  subOne = mid - begin + 1;
    size_t  subTwo = end - mid;
    Left_vec.resize(subOne);
    Right_vec.resize(subTwo);
    size_t IndexsubOne = 0;
    size_t IndexsubTwo = 0;

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

void    PmergeMe::merge_sort_vec(size_t begin, size_t end)
{
    if (begin >= end - begin)
    {
        this->insertion_sort_vec();
        return ;
    }
    size_t mid = begin + (end - begin) / 2;
    merge_sort_vec(begin, mid);
    merge_sort_vec(mid + 1, end);
    merge_vec(mid, begin, end);
}


//deque

void    PmergeMe::insertion_sort_deq()
{
    size_t len = this->deq.size();
    size_t     j;

    for (size_t i = 1; i <= len - 1; i++)
    {
        j = i;
        while (j > 0 && this->deq[j - 1] > this->deq[j])
        {
            std::swap(this->deq[j], this->deq[j - 1]);
            j = j - 1;
        }
    }
}

void    PmergeMe::merge_deq(size_t mid, size_t begin, size_t end)
{
    std::deque<int> Left_deq;
    std::deque<int> Right_deq;
    size_t  subOne = mid - begin + 1;
    size_t  subTwo = end - mid;
    Left_deq.resize(subOne);
    Right_deq.resize(subTwo);
    size_t IndexsubOne = 0;
    size_t IndexsubTwo = 0;

    for (size_t i = 0; i < subOne; i++)
        Left_deq[i] = this->deq[begin + i];
    for (size_t j = 0; j < subTwo; j++)
        Right_deq[j] = this->deq[mid + 1 + j];
    size_t Index_left = begin;
    while (IndexsubOne < subOne && IndexsubTwo < subTwo)
    {
        if (Left_deq[IndexsubOne] <= Right_deq[IndexsubTwo])
            this->deq[Index_left] = Left_deq[IndexsubOne++];
        else
            this->deq[Index_left] = Right_deq[IndexsubTwo++];
        Index_left++;
    }
    while (IndexsubOne < subOne)
        this->deq[Index_left++] = Left_deq[IndexsubOne++];
    while (IndexsubTwo < subTwo)
        this->deq[Index_left++] = Right_deq[IndexsubTwo++];
}

void    PmergeMe::merge_sort_deq(size_t begin, size_t end)
{
    if (begin >= end - begin)
    {
        this->insertion_sort_deq();
        return ;
    }
    size_t mid = begin + (end - begin) / 2;
    merge_sort_deq(begin, mid);
    merge_sort_deq(mid + 1, end);
    merge_deq(mid, begin, end);
}