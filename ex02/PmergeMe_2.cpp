#include "PmergeMe_2.hpp"

PmergeMe::PmergeMe(char *av[])
{
    check_args(av);
    pushToVector(av);
    this->Vec_it = this->vec.begin();
    merge_insertion();
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
    this->Vec_it = this->vec.begin();
    while (this->Vec_it != this->vec.end())
    {
        std::cout << (*this->Vec_it) << ' ';
        this->Vec_it++;
    }
    std::cout << std::endl;
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

void    PmergeMe::merge_insertion()
{
    std::vector< std::pair <int,int> > vect;
    size_t size = this->vec.size();
    std::vector<int> tmp;
    std::vector<int>::iterator it_tmp;

    for(size_t i = 0; i < size; i+=2)
        if (i < size - 1)
            vect.push_back(std::make_pair(this->vec[i], this->vec[i + 1]));
    size_t tmp_size = vect.size();
    tmp.resize(tmp_size);
    for(size_t i = 0; i < tmp_size; i++)
        if (vect[i].first > vect[i].second)
            std::swap(vect[i].first, vect[i].second);
    std::sort(vect.begin(), vect.end());
    for(size_t i = 0; i < tmp_size; i++)
        tmp[i] = vect[i].first;
    if (size % 2)
    {
        it_tmp = std::upper_bound(tmp.begin(), tmp.end(), this->vec[size-1]);
        tmp.insert(it_tmp, this->vec[size-1]);
    }
    for(size_t i = 0; i < tmp_size; i++)
    {
        it_tmp = std::upper_bound(tmp.begin(), tmp.end(), vect[i].second);
        tmp.insert(it_tmp, vect[i].second);
    }
    this->vec = tmp;
}