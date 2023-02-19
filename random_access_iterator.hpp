/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:28:13 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/18 23:26:39 by iouardi          ###   ########.fr       */
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
			T	data;
		public:
			typedef typename std::ptrdiff_t						difference_type;
			typedef T											value_type;
			typedef typename ft::iterator_traits<T>::pointer	pointer;
			typedef typename ft::iterator_traits<T>::reference	reference;
			typedef typename std::random_access_iterator_tag	iterator_category;
		
		public://constructors
			random_access_iterator():data(nullptr){}
			random_access_iterator(const random_access_iterator &copy): data(copy.base()){}
			template<typename RA>
			random_access_iterator(const random_access_iterator<RA> &copy): data(copy.base()){}
			random_access_iterator(pointer ptr):data(ptr){}

		public://destructor
			~random_access_iterator(){}
		
		public:
			T	base() const { return data; }
		
		public://assignement operator
			random_access_iterator& operator=(const random_access_iterator& copy)
			{
				data = copy.base();
				return *this;
			}

			reference	operator*() const { return *data; }
			pointer		operator->() const { return data; }

			//other operators
			random_access_iterator&	operator++()//pre_increment
			{
				++data;
				return *this;
			}

			random_access_iterator	operator++(int)//increment
			{
				random_access_iterator copy(*this);
				++(*this);
				return copy;
			}

			random_access_iterator&	operator--()//pre_decrement
			{
				--data;
				return *this;
			}

			random_access_iterator	operator--(int)//decrement
			{
				random_access_iterator copy(*this);
				--(*this);
				return copy;
			}
			
			random_access_iterator&	operator+=(difference_type n)
			{
				data += n;
				return *this;
			}

			random_access_iterator	operator-(difference_type n) const
			{
				return (data - n);
			}

			random_access_iterator&	operator-=(difference_type n)
			{
				data -= n;
				return *this;
			}

			reference	operator[](difference_type n) const
			{
				return *(*this + n);
			}

			// random_access_iterator	operator+(difference_type n) const
			// {
			// 	return (*this + other);
			// }
			// random_access_iterator& operator-(const random_access_iterator& other) const
			// {
			// 	return (*this - other);
			// }
			difference_type operator-(const random_access_iterator& other) const
			{
				return (this->data - other.data);
			}
			
			random_access_iterator operator+(difference_type n) const
			{
				return (data + n);
			}
			
			template <typename EQ>
			friend bool	operator==(const random_access_iterator<EQ>& it1, const random_access_iterator<EQ>& it2)
			{
				return (it1.base() == it2.base());
			}

			bool operator==(const random_access_iterator& other) const
			{
				return (data == other.base());
			}
			
			// template <class itr1, class itr2>
			// friend bool operator==(const itr1& it1, const itr2& it2)
			// {
			// 	return (it1.data == it2.data);
			// }

			template <class itr1, class itr2>
			friend bool	operator!=(const itr1& it1, const itr2& it2)
			{
				return (it1.data != it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator>(const itr1& it1, const itr2& it2)
			{
				return (it1.data > it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator>=(const itr1& it1, const itr2& it2)
			{
				return (it1.data >= it2.data);
			}

			template <class itr1, class, class itr2>
			friend bool	operator<(const itr1& it1, const itr2& it2)
			{
				return (it1.data < it2.data);
			}

			bool	operator<(const random_access_iterator& it)  const
			{
				return (data < it.data);
			}

			template <class itr1, class itr2>
			friend bool	operator<=(const itr1& it1, const itr2& it2)
			{
				return (it1.data <= it2.data);
			}

			template <class itr>
			friend	random_access_iterator	operator+(difference_type n, random_access_iterator<itr> it)
			{
				return (it.data + n);
			}

			random_access_iterator	operator-(difference_type n)
			{
				return (this->data - n);
			}
			
			template <class itr1, class itr2>
			friend difference_type	operator-(random_access_iterator<itr1> const& it1, random_access_iterator<itr2> const& it2)
			{
				return (it1.base() - it2.base());
			}
	};
	
};


#endif
