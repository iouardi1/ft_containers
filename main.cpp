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

    // ft::vector<int>::iterator  itr;
    // ft::vector<int>::iterator  itr1;
    // ft::vector<int> vec1(5, 6);

    // // itr = vec1.begin();
    // // itr1 = vec1.begin();
    // vec1[0] = 4;

    // *itr++;
    // std::cout << (*(itr++) > *itr) << std::endl; //4
    // std::cout << *(itr1) << std::endl;

    /*testing begin()*/

    // ft::vector<int> vec(5, 9);

    // vec[0] = 2;
    // std::cout << *vec.begin() << std::endl << std::endl;
    // //
    // std::vector<int> vec1(5, 9);

    // vec1[0] = 2;
    // std::cout << *vec1.begin() << std::endl;

    /* testing const begin()*/

    // const ft::vector<int> vec(5, 45);

    // std::cout << *vec.begin() << std::endl << std::endl;
    
    // const std::vector<int> vec1(5, 45);

    // std::cout << *vec1.begin() << std::endl;

    /*testing end()*/
    // ft::vector<int> vec(5, 45);

    // vec[4] = 2;
    // std::cout << *vec.end() << std::endl << std::endl;
    
    // std::vector<int> vec1(5, 45);

    // std::cout << *vec1.end() << std::endl;

    /*testing const end()*/
    // const ft::vector<int> vec(5, 45);

    // std::cout << *vec.end() << std::endl << std::endl;
    
    // const std::vector<int> vec1(5, 45);

    // std::cout << *vec1.end() << std::endl;


    /*testing rbegin()*/
    ft::vector<int> vec(5, 45);

    std::cout << *vec.rbegin() << std::endl << std::endl;
    
    std::vector<int> vec1(5, 45);

    std::cout << *vec1.rbegin() << std::endl;

    // ft::vector<int> myvector(5, 9);
  // for (int i=0; i<10; i++) myvector.push_back(i);

  // typedef ft::vector<int>::iterator iter_type;

  // ft::reverse_iterator<iter_type> rev_end (myvector.begin());
  // ft::reverse_iterator<iter_type> rev_begin (myvector.end());

  // std::cout << "myvector:";
  // for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  // std::cout << *myvector.rbegin() << std::endl;

}