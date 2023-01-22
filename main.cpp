#include <iostream>
#include <vector>
#include "vector.hpp"
int main()
{
    std::vector<int>::iterator itr;
    // std::vector<int> vec(5, 10);
    // std::vector<int> vec1(vec.begin(), vec.end());
    // ft::vector<int> vec(5, 10);
    ft::vector<int> vec1(5, 10);
    // ft::vector<int> vec1(5, 7);

    std::cout << vec1[4] << std::endl;
}