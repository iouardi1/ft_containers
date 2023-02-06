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


	//* ************************************************* *//
		// ft::vector<int>::iterator  itr;
		// ft::vector<int>::iterator  itr1;
		// ft::vector<int> vec1(5, 6);

		// // itr = vec1.begin();
		// // itr1 = vec1.begin();
		// vec1[0] = 4;

		///* *itr++;
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
	//* ************************************************* *//

		///* testing const begin() */

		// const ft::vector<int> vec(5, 45);

		// std::cout << *vec.begin() << std::endl << std::endl;
		
		// const std::vector<int> vec1(5, 45);

		// std::cout << *vec1.begin() << std::endl;
	//* ************************************************* *//

		///* testing end() */
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
	//* ************************************************* *//

		///* testing rbegin() */
		
		// std::vector<int> vec1(5, 45);
		
		// vec1[4] = 5;
		// std::cout << *vec1.rbegin() << std::endl;
		// ft::vector<int> vec(5, 45);

		// vec[4] = 5;
		// std::cout << *vec.rbegin() << std::endl << std::endl;
	//* ************************************************* *//

	///* testing rend() */
		// std::vector<int> vec1(5, 45);
		
		// vec1[-1] = 5;
		// std::cout << *vec1.rend() << std::endl;
		// ft::vector<int> vec(5, 45);

		// vec[-1] = 5;
		// std::cout << *vec.rend() << std::endl << std::endl;
	//* ************************************************* *//

	///* testing resize() */

	// ft::vector<int> myvector(10, 5);

	// // set some initial content:
	// // for (int i=1;i<10;i++) myvector.push_back(i);

	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;
	// myvector.resize(5);
	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;
	// myvector.resize(3);
	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;
	// myvector.resize(8,100);
	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;
	// myvector.resize(19);
	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;
	// myvector.resize(21);
	// std::cout << myvector.capacity() << "   and size : " << myvector.size() << std::endl;

	// std::cout << '\n';
	// ///----std
	// std::vector<int> myvector1(10, 5);

	// // set some initial content:
	// // for (int i=1;i<10;i++) myvector1.push_back(i);

	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;
	// myvector1.resize(5);
	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;
	// myvector1.resize(3);
	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;
	// myvector1.resize(8,100);
	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;
	// myvector1.resize(19);
	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;
	// myvector1.resize(21);
	// std::cout << myvector1.capacity() << "   and size : " << myvector1.size() << std::endl;

	// std::cout << '\n';
	//* ************************************************* *//

	// * testing empty() * //
	// ft::vector<int> myvector(1);

	// std::cout << "total: " << myvector.empty() << '\n';
	// ///----std
	// std::vector<int> myvector1(1);

	// std::cout << "total: " << myvector1.empty() << '\n';
	//* ************************************************* *//

	// * testing empty() * //

	// std::vector<int>::size_type sz;

	// std::vector<int> foo;
	// sz = foo.capacity();
	// std::cout << "making foo grow:\n";
	// for (int i=0; i<100; ++i) {
	// 	foo.push_back(i);
	// 	if (sz!=foo.capacity()) {
	// 	sz = foo.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// std::vector<int> bar;
	// sz = bar.capacity();
	// bar.reserve(100);   // this is the only difference with foo above
	// std::cout << "making bar grow:\n";
	// for (int i=0; i<100; ++i) {
	// 	bar.push_back(i);
	// 	if (sz!=bar.capacity()) {
	// 	sz = bar.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
  	// }
	//* ************************************************* *//

	// * testing at * //
	// ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// // assign some values:
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	myvector.at(i)=i;

	// std::cout << "myvector contains:";
	// for (unsigned i=0; i<myvector.size(); i++)
	// 	std::cout << ' ' << myvector.at(i);
	// std::cout << '\n';
	// ///----std 
	// std::vector<int> myvector1 (10);   // 10 zero-initialized ints

	// // assign some values:
	// for (unsigned i=0; i<myvector1.size(); i++)
	// 	myvector1.at(i)=i;

	// std::cout << "myvector1 contains:";
	// for (unsigned i=0; i<myvector1.size(); i++)
	// 	std::cout << ' ' << myvector1.at(i);
	// std::cout << '\n';
	//* ************************************************* *//

	// * testing front * //
	std::vector<int> myvector(3);

	myvector[0] = 16;
	myvector[1] = 72;

	// now front equals 78, and back 16

	// std::cout << "myvector.front() is now " << myvector.front() << '\n';
	// myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';

}