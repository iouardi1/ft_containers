/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:05:01 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/08 16:37:35 by iouardi          ###   ########.fr       */
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
			typedef	typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		
		public:
			///for constructors
			explicit vector (const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), arr(NULL), alloc(alloc)
			{}
	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), alloc(alloc)
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
				_size = j;
				_capacity = j;
				this->alloc = alloc;
				arr = this->alloc.allocate(j);
				j = 0;
				for (InputIterator i = first; i != last; i++)
				{
					alloc.construct(arr + j, *i);
					j++;
				}
			}

			vector (const vector& x): _size(x._size), _capacity(x._capacity), alloc(x.alloc)
			{
				*this = vector(x.begin(), x.end());
			}
			
			~vector()
			{
				if (arr)
					alloc.deallocate(arr, _capacity);
			}

		public:
			///exceptions
			class out_of_range : public std::exception
			{
				const char* what() const throw()
				{
					return "out_of_range";
				}
			};
		public:
			///overloaded operators
			const_reference operator[] (size_type n) const
			{
				return (arr[n]);
			}

			reference operator[] (size_type n)
			{
				return (arr[n]);
			}
			
			reference at (size_type n)
			{
				if (n <= _size)
					return (operator[](n));
				else
					throw out_of_range();
			}

			const_reference at (size_type n) const
			{
				if (n <= _size)
					return (operator[](n));
				else
					throw out_of_range();
			}
			
			reference	front()
			{
				return *(this->begin());
			}

			const_reference front() const
			{
				return *(this->begin());
			}
			
			reference	back()
			{
				return *(this->end() - 1);
			}
	
			const_reference	back() const
			{
				return *(this->end() - 1);
			}
			
			vector& operator= (const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				alloc = x.alloc;
				arr = alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					alloc.construct(arr + i, x.arr[i]);//to be seen l a t e r
				return (*this);
			}
		public:
			///member functions
			iterator	begin()
			{
				return iterator(arr);
			}

			const_iterator	begin() const 
			{
				return const_iterator(arr);
			}

			iterator	end()
			{
				return iterator(arr + _size); 
			}

			const_iterator	end() const 
			{
				return const_iterator(arr + _size); 
			}

			reverse_iterator	rbegin()
			{
				return reverse_iterator(this->end());
			}

			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(this->end());
			}

			reverse_iterator	rend()
			{
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(this->begin());
			}

		public:
			///capacity
			size_type	size() const
			{
				return (this->_size);
			}

			size_type	max_size() const
			{
				return (this->_capacity);
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n < _capacity)
				{
					this->alloc.destroy(this->arr + n);
					this->_size = n;
				}
				else
				{
					this->alloc.allocate(n - _capacity);
					for (size_type i = _capacity; i < n; i++)
						this->alloc.construct(arr + _capacity, val);
					this->_size = n;
					if (n > _capacity * 2)
						this->_capacity = n;
					else
						this->_capacity *= 2;
				}
			}

			size_type	capacity() const
			{
				return this->_capacity;
			}

			bool	empty() const
			{
				return (!_size);
			}

			void	reserve(size_type n)
			{
				if (n > _capacity)
				{	
					value_type	*tmp = this->alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						this->alloc.construct(tmp + i, arr[i]); /// hmmmmm :3
						this->alloc.destroy(arr + i);
					}
					alloc.deallocate(arr, _capacity);
					arr = tmp;
					this->_capacity = n;
				}
			}

		public:
			///modifiers
			template <class InputIterator>
			void	assign(InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, T>::type last)
			{
				size_type	j = 0;
				for (InputIterator i = first; i != last; i++)
					j++;
				if (j > _capacity)
					reserve(j);
				j = 0;
				for (InputIterator i = first; i != last; i++)
				{
					this->alloc.construct(arr + j, *i);
					j++;
				}
				_size = j;
			}

			void	assign(size_type n, const value_type& val)
			{
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					this->alloc.construct(arr + i, val);
				_size = n;
			}

			void	push_back(const value_type& val)
			{
				if (_size == _capacity)
				{
					size_type i;
					if (_capacity == 0)
						i = 1;
					else
						i = _capacity * 2;
					reserve(i);
				}
				this->alloc.construct(arr + (_size++) , val);
			}
			
			void pop_back()
			{
				if (_size > 0)
				{
					_size -= 1;
					this->alloc.destroy(arr + _size);
				}
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				size_type j(0);
				for (iterator i = begin(); i != position; i++)
					j++;
				if (_size == _capacity)
				{
					size_type	i;

					if (_size == 0)
						i = 1;
					else
						i = _capacity * 2;
					reserve(i);
				}
				for (size_type l = _size; l > j; --l)
				{
					this->alloc.construct(arr + l, val);
					
				}
			}
				
				
		private:
			size_type		_size;
			size_type		_capacity;
			Alloc			alloc;
			value_type		*arr;


	};
}

#endif
