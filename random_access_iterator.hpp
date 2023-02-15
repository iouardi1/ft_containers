/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:28:13 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/14 19:02:37 by iouardi          ###   ########.fr       */
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

//reverse iterator
namespace ft
{
	template <class Iterator> class reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

		//constructors
		
		public:
			reverse_iterator(): _current(){}
			explicit reverse_iterator(iterator_type it): _current(it){}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it): _current(rev_it.base()) {}

		//overloaded operators
		public:
			reverse_iterator& operator=(const reverse_iterator<iterator_type>& copy)
			{
				_current = copy.base();
				return *this;
			}
			reference	operator*() const 
			{
				Iterator tmp = _current;
				return *--tmp; 
			}
			pointer	operator->() const
			{
				return &(operator*());
			}
			reverse_iterator&	operator++()
			{
				--_current;
				return *this;
			}
			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp(*this);
				
				--_current;
				return tmp;
			}
			reverse_iterator& operator--()
			{
				++_current;
				return *this;
			}
			reverse_iterator  operator--(int)
			{
				reverse_iterator	tmp(*this);
				++_current;
				return	tmp;
			}
			reverse_iterator	operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}
			reverse_iterator&	operator+=(difference_type n)
			{
				_current -= n;
				return *this;
			}
			reverse_iterator	operator-(difference_type n) const
			{
				return reverse_iterator(_current + n);
			}
			reverse_iterator&	operator-=(difference_type __n)
			{
				_current += __n;
				return *this;
			}
			reference	operator[](difference_type n) const
			{
				return *(*this + n);
			}

		//member functions
		public:
			iterator_type	base() const { return _current; }

		protected:
			iterator_type	_current;
	};
			//relational operators are a non member functions
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}
	template <class Iterator>
	reverse_iterator<Iterator>	operator-(typename ft::reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() + n);
	}
	
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
			random_access_iterator(const random_access_iterator &copy): data(copy.data){}
			template<typename RA>
			random_access_iterator(const random_access_iterator<RA> &copy): data(copy.data){}
			random_access_iterator(pointer ptr):data(ptr){}
		
		public:
			T	base() const { return data; }
		
		public://assignement operator
			random_access_iterator& operator=(const random_access_iterator& copy)
			{
				data = copy.data;
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
				return random_access_iterator(data - n);
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

			random_access_iterator& operator+(const random_access_iterator& other) const
			{
				return (*this + other);
			}
			random_access_iterator& operator-(const random_access_iterator& other) const
			{
				return (*this - other);
			}
			
			random_access_iterator& operator+(difference_type n) const
			{
				return (random_access_iterator(data + n));
			}
			
			template <class itr1, class itr2>
			friend	bool	operator==(const itr1& it1, const itr2& it2) const
			{
				return (it1.data == it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator!=(const itr1& it1, const itr2& it2) const
			{
				return (it1.data != it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator>(const itr1& it1, const itr2& it2) const
			{
				return (it1.data > it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator>=(const itr1& it1, const itr2& it2) const
			{
				return (it1.data >= it2.data);
			}

			template <class itr1, class, class itr2>
			friend bool	operator<(const itr1& it1, const itr2& it2) const
			{
				return (it1.data < it2.data);
			}

			template <class itr1, class itr2>
			friend bool	operator<=(const itr1& it1, const itr2& it2) const
			{
				return (it1.data <= it2.data);
			}

			random_access_iterator	operator+(difference_type n) const
			{
				random_access_iterator	itr;

				itr = *this;
				this->_current += n;
				return itr;
			}

			template <class itr>
			friend	random_access_iterator	operator+(difference_type n, random_access_iterator<itr> it)
			{
				return (it._current + n);
			}

			random_access_iterator	operator-(difference_type n) const
			{
				return (this->_current - n);
			}
			
			template <class itr1, class itr2>
			friend difference_type	operator-(random_access_iterator<itr1> const it1, random_access_iterator<itr2> const it2)
			{
				return (itr1._current - itr2._current);
			}
	};
	
};


#endif
