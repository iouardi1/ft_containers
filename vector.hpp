/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:05:01 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/04 22:38:20 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <vector>
#include "random_access_iterator.hpp"

namespace ft
{	
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			typedef	T															value_type;
			typedef	size_t														size_type;
			typedef	std::allocator<T>											allocator_type;
			typedef	typename allocator_type::reference							reference;
			typedef	typename allocator_type::const_reference					const_reference;
			typedef	typename allocator_type::pointer							pointer;
			typedef	typename allocator_type::const_pointer						const_pointer;
			typedef	typename ft::random_access_iterator<pointer>				iterator;
			typedef	typename ft::random_access_iterator<const_pointer>			const_iterator;
			typedef	typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		
		public:
		//for constructors
			explicit vector (const allocator_type& alloc = allocator_type()): size(0), capacity(0), arr(NULL), alloc(alloc)
			{}
	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): size(n), capacity(n), alloc(alloc)
			{
				arr = this->alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->alloc.construct(arr + i, val);
			}
		
			template <class InputIterator>
			
			vector (InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, T>::type last, const allocator_type& alloc = allocator_type())
			{
				size_type j = 0;
				for (InputIterator i = first; i != last; i++)
					j++;
				size = j;
				capacity = j;
				this->alloc = alloc;
				arr = this->alloc.allocate(j);
				j = 0;
				for (InputIterator i = first; i != last; i++)
				{
					alloc.construct(arr + j, *i);
					j++;
				}
			}

			vector (const vector& x): size(x.size), capacity(x.capacity), alloc(x.alloc)
			{
				*this = vector(x.begin(), x.end());
			}
			
			~vector()
			{
				if (arr)
					alloc.deallocate(arr, capacity);
			}
		
		public:
		//overloaded operators
			const_reference operator[] (size_type n) const
			{
				return (arr[n]);
			}

			reference operator[] (size_type n)
			{
				return (arr[n]);
			}
			
			vector& operator= (const vector& x)
			{
				size = x.size;
				capacity = x.capacity;
				alloc = x.alloc;
				arr = alloc.allocate(capacity);
				for (size_type i = 0; i < capacity; i++)
					alloc.construct(arr + i, x.arr[i]);//to be seen l a t e r
				return (*this);
			}
			public:
			//member functions
				iterator	begin(){return ft::random_access_iterator<pointer>(arr); }
				const_iterator	begin() const {return ft::random_access_iterator<const_pointer>(arr); }
				iterator	end(){return ft::random_access_iterator<pointer>(arr + size); }
				const_iterator	end() const {return ft::random_access_iterator<const_pointer>(arr + size); }
				reverse_iterator	rbegin()
				{
					return ft::reverse_iterator<iterator>(ft::random_access_iterator<pointer>(arr + (size - 1)));
				}
		private:
			size_t		size;
			size_t		capacity;
			Alloc		alloc;
			value_type	*arr;


	};
}

#endif
