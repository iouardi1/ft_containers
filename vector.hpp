/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:05:01 by iouardi           #+#    #+#             */
/*   Updated: 2023/02/20 01:04:33 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <vector>
#include <algorithm>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{	
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			typedef	T															value_type;
			typedef	size_t														size_type;
			typedef	Alloc														allocator_type;
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
			explicit vector (const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), alloc(alloc), arr(NULL)
			{}
	
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), alloc(alloc)
			{
				this->arr = this->alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->alloc.construct(arr + i, val);
			}
		
			template <class InputIterator>
			vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type())
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
					this->alloc.construct(arr + j, *i);
					j++;
				}
			}

			vector (const vector& x)
			{
				_size = 0;
				_capacity = 0;
				this->arr = nullptr;
				*this = x;
			}
			
			~vector()
			{
				if (arr)
				{
					for (size_t	i = 0; i < _size; i++)
						alloc.destroy(arr + i);
					if (_capacity)
						alloc.deallocate(arr, _capacity);
				}
			}

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
				if (n < _size)
					return (operator[](n));
				else
					throw std::out_of_range("vector");
			}

			const_reference at (size_type n) const
			{
				if (n < _size)
					return (operator[](n));
				else
					throw std::out_of_range("vector");
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
				if (this != &x)
				{
					clear();
					if (_capacity > 0)
						this->alloc.deallocate(arr, _capacity);
					this->alloc = x.alloc;
					this->_capacity = x._capacity;
					this->_size = x._size;
					if (_capacity > 0)
						this->arr = this->alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						this->alloc.construct(arr + i, x.arr[i]);//to be seen l a t e r
				}
				return (*this);
			}
	
		public:
			///member functions
			void	clear()
			{
				for (size_type	i = 0; i < _size; i++)
					alloc.destroy(arr + i);
				_size = 0;
			}
			
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
				return (this->alloc.max_size());
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw std::length_error("resize issues");
				if (n == _size)
					return ;
				if (n < _size)
				{
					while (n != _size)
						pop_back();
				}
				else
				{
					if (n > _capacity * 2)
						reserve (n);
					else if (n > _capacity)
						reserve (_capacity * 2);
					while (n !=  _size)
						insert (this->end(), n - _size, val);
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
				if (n <= _capacity)
					return ;
				value_type	*tmp = alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					alloc.construct(tmp + i, arr[i]);
					alloc.destroy(arr + i);
				}
				if (_capacity)
					alloc.deallocate(arr, _capacity);
				arr = tmp;
				_capacity = n;
			}

		public:
			///modifiers
			template <class InputIterator>
			void	assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
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

			iterator insert(iterator position, const value_type& val)
			{
				//* il fallait juste de separer les cas, _size > _capacity: in this case we should construct, otherwise
				//* il fallait juste de les deplacer :3
				
				size_type	pos_index = position - begin();
				if (_size == _capacity)
				{
					size_type	new_capacity = (_capacity == 0) ?  1 : _capacity * 2;
					T	*tmp = this->alloc.allocate(new_capacity);
					for (size_type i = 0; i < pos_index; i++)
					{
						this->alloc.construct(tmp + i, arr[i]);
						this->alloc.destroy(arr + i);
					}
					alloc.construct(tmp + pos_index, val);
					for (size_type i = pos_index; i < _size; ++i)
					{
						this->alloc.construct(tmp + (i + 1), arr[i]);
						this->alloc.destroy(arr + i);
					}
					this->alloc.deallocate(arr , _capacity);
					arr = tmp;
					_capacity = new_capacity;
				}
				else
				{
					this->alloc.construct(arr + _size, arr[_size - 1]);
					for (size_type i = _size - 1; i > pos_index; --i)
						arr[i] = arr[i - 1];
					arr[pos_index] = val;
				}
				_size += 1;
				return (begin() + pos_index);
			}

			
			void	insert(iterator position, size_type	n, const value_type& val)
			{
				size_type	pos_index = position - begin();
				if (n == 0)
					return ;
				if (_size + n > _capacity)
				{
					size_type	newCapacity = (2 * _capacity) > (_size + n) ? (2 * _capacity) : (_size + n);
					T			*new_arr = this->alloc.allocate(newCapacity);
					
					for (size_type	i = 0; i < pos_index; i++)
					{
						alloc.construct(new_arr + i, arr[i]);
						alloc.destroy(arr + i);
					}
					for (size_type	i = 0; i < n; i++)
						alloc.construct(new_arr + pos_index + i, val);
					for (size_type	i = pos_index; i < _size; i++)
					{
						alloc.construct(new_arr + n + i, arr[i]);
						alloc.destroy(arr + i);
					}
					alloc.deallocate(arr, _capacity);
					arr = new_arr;
					_capacity = newCapacity;
				}
				else
				{
					for (size_type	i = _size + n - 1; i >= pos_index + n; i--)
						arr[i] = arr[i - n];
					for (size_type	i = 0; i < n; i++)
						alloc.construct(arr + pos_index + i, val);
				}
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
			{
				size_type	n = 0;
				for (InputIterator i = first; i != last; i++)
					n++;
				if (!n)
					return ;
				if (_size + n > _capacity)
				{
					size_type	i;
					T			*new_arr;
					size_type	newCapacity;
					try {
						newCapacity = (2 * _capacity) > (_size + n) ? 2 * _capacity : _size + n;
						new_arr = this->alloc.allocate(newCapacity);

						size_type	pos_index = position - begin();

						for (i = 0; i < pos_index; i++)
						{
							alloc.construct(new_arr + i, arr[i]);
							alloc.destroy(arr + i);
						}
						// size_type	pos_index_tmp = pos_index;
						while (first != last)
						{
							this->alloc.construct(new_arr + i++, *first++);
						}
						
						for (; i < _size + n; i++)
						{
							this->alloc.construct(new_arr + i, arr[pos_index]);
							this->alloc.destroy(arr + pos_index);
							pos_index++;
						}
						if (_capacity)
							this->alloc.deallocate(arr, _capacity);
						arr = new_arr;
						_capacity = newCapacity;
					}
					catch(...){
						while (--i)
							alloc.destroy(new_arr + i);
						alloc.deallocate(new_arr, newCapacity);
					}
				}
				else
				{
					size_type	i = 0;

					for (iterator	j = end(); j > position; --j)
					{
						i++;
						arr[_size + n - i] = *(j - 1);
					}
					size_type	pos_index = (position - begin());
					while (first != last)
						this->alloc.construct(arr + pos_index++, *first++);
				}
				_size += n;
			}

			iterator erase(iterator position)
			{
				if (position >= end() || position < begin())
					throw std::out_of_range("vector");
				T	*pos = position.base();

				this->alloc.destroy(pos);

				for (T	*i = pos + 1; i < arr + _size; i++)
				{
					this->alloc.construct(i - 1, *i);
					this->alloc.destroy(i);
				}
				_size -= 1;
				return iterator(pos);
			}
			
			iterator erase (iterator first, iterator last)
			{
				if (first >= last || first >= end() || last > end() || first < begin() || last < begin())
					throw std::out_of_range("vector");
				
				T	*start = first.base();
				T	*end = last.base();

				for (T	*i = start; i < end; i++)
					this->alloc.destroy(i);

				for (T	*j = end; j < arr + _size; j++)
				{
					this->alloc.construct(j - (end - start), *j);
					this->alloc.destroy(j);
				}
				_size -= end - start;
				return iterator(start);
			}
			
			void swap (vector& x)
			{
				if (this == &x)
       				return;

				// Swap capacity
				size_type tmp_capacity = _capacity;
				_capacity = x._capacity;
				x._capacity = tmp_capacity;

				// Swap size
				size_type tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;

				// Swap data
				T* tmp_arr = arr;
				arr = x.arr;
				x.arr = tmp_arr;

				// Swap allocator
				allocator_type	tmp_alloc = this->alloc;
				alloc = x.get_allocator();
				x.alloc = tmp_alloc;
			}

			template <class T1, class Alloc1>
			friend	void swap (vector <T1, Alloc1>& x, vector <T1, Alloc1>& y);
			
			//* getters *//
			Alloc	get_allocator()
			{
				return (this->alloc);
			}
			
		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	alloc;
			value_type		*arr;


	};
	//* overloaded non member functions operators
	template <class T>
	bool	operator==(const vector<T>& vec1, const vector<T>& vec2)
	{
		if (vec1.size() != vec2.size())
			return	false;
		for (size_t i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] != vec2[i])
				return	false;
		}
		return true;
	}
	
	template <class T>
	bool	operator!=(const vector<T>& vec1, const vector<T>& vec2)
	{
		return !(vec1 == vec2);
	}

	template <class T>
	bool	operator<(const vector<T>& vec1, const vector<T>& vec2)
	{
		size_t	minSize = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
		for (size_t i = 0; i < minSize; i++)// recheck  later ++i
		{
			if (vec1[i] < vec2[i])
				return true;
			else if (vec1[i] > vec2[i])
				return false;
		}
		return (vec1.size() < vec2.size());
	}

	template <class T>
	bool	operator<=(const vector<T>& vec1, const vector<T>& vec2)
	{
		return !(vec2 < vec1);
	}

	template <class T>
	bool	operator>(const vector<T>& vec1, const vector<T>& vec2)
	{
		return (vec2 < vec1);
	}

	template <class T>
	bool	operator>=(const vector<T>& vec1, const vector<T>& vec2)
	{
		return !(vec2 > vec1);
	}

	template <class T1, class Alloc1>
	void swap (vector<T1,Alloc1>& x, vector<T1,Alloc1>& y)
	{
		if (&y == &x)
			return;

		// Swap capacity
		size_t	tmp_capacity = y.capacity();
		y._capacity = x.capacity();
		x._capacity = tmp_capacity;

		// Swap size
		size_t tmp_size = y.size();
		y._size = x.size();
		x._size = tmp_size;

		// Swap data
		T1* tmp_arr = y.arr;
		y.arr = x.arr;
		x.arr = tmp_arr;

		// Swap allocator
		typename vector<T1,Alloc1>::allocator_type	tmp_alloc = y.get_allocator();
		y.alloc = x.get_allocator();
		x.alloc = tmp_alloc;
	}
}

#endif
