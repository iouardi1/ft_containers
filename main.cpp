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

	// * testing reserve * //
	// ft::vector<int> vec(10);

	// std::cout << vec.capacity() << '\n';
	// std::cout << vec.size() << '\n';
	// vec.reserve(30);
	// std::cout << vec.capacity() << '\n';
	// std::cout << vec.size() << '\n';
	// vec.reserve(5);
	// std::cout << vec.capacity() << '\n';
	// std::cout << vec.size() << '\n';
	
	// ///std
	// std::cout << "\n";
	// std::vector<int> vec1(10);
	
	// std::cout << vec1.capacity() << '\n';
	// std::cout << vec1.size() << '\n';
	// vec1.reserve(30);
	// std::cout << vec1.capacity() << '\n';
	// std::cout << vec1.size() << '\n';
	// vec1.reserve(5);
	// std::cout << vec1.capacity() << '\n';
	// std::cout << vec1.size() << '\n';

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

	// * testing front and back* //
	// ft::vector<int> myvector(3);

	// myvector[0] = 16;
	// myvector[1] = 72;

	// std::cout << "myvector.front() is now " << myvector.front() << '\n';
	// std::cout << "myvector.back() is now " << myvector.back() << '\n';
	// /// std 
	// std::vector<int> myvector1(3);
	// myvector1[0] = 16;
	// myvector1[1] = 72;

	// std::cout << "myvector1.front() is now " << myvector1.front() << '\n';
	// std::cout << "myvector1.back() is now " << myvector1.back() << '\n';
	//* ************************************************* *//

	// * testing asssign * //
	// std::vector<int> first;
	// std::vector<int> second;
	// std::vector<int> third;

	// first.assign (7,100);             // 7 ints with a value of 100

	// std::vector<int>::iterator it;
	// it=first.begin()+1;

	// second.assign (it,first.end()-1); // the 5 central values of first

	// int myints[] = {1776,7,4};
	// third.assign (myints,myints+3);   // assigning from array.

	// std::cout << "Size of first: " << int (first.size()) << "  " << *first.begin()<< '\n';
	// std::cout << "Size of second: " << int (second.size()) << "  " << *second.begin() << '\n';
	// std::cout << "Size of third: " << int (third.size()) << "  " << *third.begin() << '\n';
	// std::cout << "\n" ;
	// ///-----ft
	// ft::vector<int> first1;
	// ft::vector<int> second1;
	// ft::vector<int> third1;

	// first1.assign (7,100);             // 7 ints with a value of 100

	// ft::vector<int>::iterator it1;
	// it1 = first1.begin()+1;

	// second1.assign (it1,first1.end()-1); // the 5 central values of first1

	// int myints1[] = {1776,7,4};
	// third1.assign (myints1,myints1+3);   // assigning from array.

	// std::cout << "Size of first1: " << int (first1.size()) << "  " << *first1.begin()<< '\n';
	// std::cout << "Size of second1: " << int (second1.size()) << "  " << *second1.begin() << '\n';
	// std::cout << "Size of third1: " << int (third1.size()) << "  " << *third1.begin() << '\n';

	//* ************************************************* *//
	// * testing push_back * //
	// ft::vector<int> myvector;
	// int myint;


	// std::cout << "Please enter some integers (enter 0 to end):\n";

	// do {
	// 	std::cin >> myint;
	// 	myvector.push_back (myint);
	// } while (myint);

	// std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	// std::cout << "myvector stores " << int(myvector.capacity()) << " numbers.\n\n";
	// /// std
	// std::vector<int> myvector1;
	// int myint1;

	// std::cout << "Please enter some integers (enter 0 to end):\n";

	// do {
	// 	std::cin >> myint1;
	// 	myvector1.push_back (myint1);
	// } while (myint1);

	// std::cout << "myvector1 stores " << int(myvector1.size()) << " numbers.\n";
	// std::cout << "myvector1 stores " << int(myvector1.capacity()) << " numbers.\n";

	//* ************************************************* *//
	// * testing pop_back * //
	// ft::vector<int> myvector;
	// int sum (0);
	// myvector.push_back (100);
	// myvector.push_back (200);
	// myvector.push_back (300);

	// while (!myvector.empty())
	// {
	// 	sum+=myvector.back();
	// 	std::cout << "elements: " << myvector.back() << std::endl;
	// 	myvector.pop_back();
	// }

	// std::cout << "The elements of myvector add up to " << sum << "\n\n";
	// ///std
	// std::vector<int> myvector1;
	// int sum1 (0);
	// myvector1.push_back (100);
	// myvector1.push_back (200);
	// myvector1.push_back (300);

	// while (!myvector1.empty())
	// {
	// 	std::cout << "elements: " << myvector1.back() << std::endl;
	// 	sum1+=myvector1.back();
	// 	myvector1.pop_back();
	// }

	// std::cout << "The elements of myvector1 add up to " << sum1 << '\n';
	//* ************************************************* *//
	// * testing insert iterator position, const value_type& val)* //
	// ft::vector<int> myvector (3,100);
	// ft::vector<int>::iterator it;

	// it = myvector.begin();
	// *++it;
	// it = myvector.insert ( it , 200 );
	// for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); *++it)
	// 	std::cout << *it << "\n";
	// std::cout << "\n";
	// /// std 
	// std::vector<int> myvector1 (3,100);
	// std::vector<int>::iterator it1;

	// it1 = myvector1.begin();
	// *++it1;
	// it1 = myvector1.insert ( it1 , 200 );
	// for (std::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); *++it1)
	// 	std::cout << *it1 << '\n';
	//* ************************************************* *//
	// * testing insert (iterator position, size_type	n, const value_type& val)
	// ft::vector<int> myvector (3,100);
	// ft::vector<int>::iterator it;

	// it = myvector.begin();

	// myvector.insert (++it,2,300);

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
	// /// std 
	// std::vector<int> myvector1 (3,100);
	// std::vector<int>::iterator it1;

	// it1 = myvector1.begin();

	// myvector1.insert (++it1,2,300);

	// // "it1" no longer valid, get a new one:
	// it1 = myvector1.begin();

	// for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
	// 	std::cout << ' ' << *it1;
	// std::cout << '\n';
	//* ************************************************* *//
	// * testing insert (iterator position, typename std::enable_if<!std::is_integral<InputIterator>::value, T>::type first, InputIterator last) *//
	// ft::vector<int> myvector (5,100);
	// ft::vector<int>::iterator it;

	// it = myvector.begin();
	// it+=2;
	// myvector.insert ( it , 200 );

	// myvector.insert (it,2,300);

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// ft::vector<int> anothervector (2,400);
	// myvector.insert ((it + 2), anothervector.begin(), anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, (myarray+3));

	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
	/// std 
	// std::vector<int> myvector1 (3,100);
	// std::vector<int>::iterator it1;

	// it1 = myvector1.begin();
	// it1 = myvector1.insert ( it1 , 200 );

	// myvector1.insert (it1,2,300);

	// // "it1" no longer valid, get a new one:
	// it1 = myvector1.begin();

	// std::vector<int> anothervector1 (2,400);
	// myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());

	// int myarray1 [] = { 501,502,503 };
	// myvector1.insert (myvector1.begin(), myarray1, myarray1+3);

	// std::cout << "myvector1 contains:";
	// for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
	// 	std::cout << ' ' << *it1;
	// std::cout << '\n';
	//* ************************************************* *//
    //* testing iterators *//

    ft::vector<int> myvector(10, 7);
   ft::vector<int>::iterator myiterator(myvector.begin());
//    ft::vector<int>::iterator myiterator1(myvector.begin() + 2);

    std::cout << &(*(1 +  myiterator));
}



