/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:05:01 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/22 19:36:42 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <vector>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			typedef	T											value_type;
			typedef	size_t										size_type;
			typedef	std::allocator<T>							allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
		public://for constructors
			explicit vector (const allocator_type& alloc = allocator_type()): size(0), capacity(0), arr(NULL), alloc(alloc)
			{}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): size(n), capacity(n), alloc(alloc)
			{
				arr = this->alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					arr[i] = val;
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
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
					arr[j++] = *i;
			}
		public://overloaded operator
			const_reference operator[] (size_type n) const
			{
				return (arr[n]);
			}
			reference operator[] (size_type n)
			{
				return (arr[n]);
			}
			
		private:
			size_t		size;
			size_t		capacity;
			value_type	*arr;
			Alloc		alloc; 
		

	};
}



#endif
