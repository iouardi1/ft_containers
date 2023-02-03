#include <iostream>
#include <vector>
#include "vector.hpp"
int main()
{
    // std::vector<int>::iterator itr;
    // std::vector<int> vec(5, 10);
    // std::vector<int> vec1(vec.begin(), vec.end());
    // ft::vector<int> vec(5, 10);
    // ft::vector<int> vec1(5, 10);
    // ft::vector<int> vec1(5, 7);

    // std::cout << vec1[4] << std::endl;

    // using iterator_type = std::vector<int>::iterator;
    // using value_type = std::iterator_traits<iterator_type>::value_type;
    // value_type v;

    // std::cout << v << std::endl;

    // std::vector<int> vec(5, 6);


///

    std::vector<int>::iterator  itr;
    std::vector<int>::iterator  itr1;
    std::vector<int> vec1(5, 6);

    itr = vec1.begin();
    itr1 = vec1.begin();
    vec1[0] = 4;

    // *itr++;
    std::cout << *(itr++) << std::endl; //4
    std::cout << *(itr1) << std::endl;
}