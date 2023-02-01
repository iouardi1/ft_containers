/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:28:13 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/01 18:03:07 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR
#define RANDOM_ACCESS_ITERATOR
#include <iostream>


//iterator_traits
namespace ft
{
	template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;	//==> distance between two iterators
		typedef typename Iter::value_type 			value_type;			//==> the type of the value pointed to by the iterator
		typedef typename Iter::pointer 				pointer;			//==> pointer to the value pointed to by the iterator
		typedef typename Iter::reference 			reference;			//==> reference to the value pointed to by the iterator
		typedef typename Iter::iterator_category 	iterator_category;	//==> describes the operations of the iterator
	};

	//
	template <typename T>
	struct iterator_traits<T*>
	{
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	};

	//
	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef typename std::ptrdiff_t						difference_type;
		typedef  T											value_type;
		typedef  const T*									pointer;
		typedef  const T&									reference;
		typedef	typename std::random_access_iterator_tag	iterator_category;
	};
	
};

//random_access_iterator
namespace ft
{
	template <typename T>
	class random_access_iterator
	{
		private:
			T*		data;
		public:
			typedef typename std::ptrdiff_t						difference_type;
			typedef T											value_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef typename std::random_access_iterator_tag	iterator_category;
		
		public://constructors
			random_access_iterator():data(nullptr){}
			random_access_iterator(T* ptr):data(ptr){}

			
			
			
			
	};
}


#endif
