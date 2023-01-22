/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:05:01 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/22 15:33:42 by iouardi          ###   ########.fr       */
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
			typedef	allocator									allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointor			pointor;
			typedef	typename allocator_type::const_pointor		const_pointor;
		private:
			size_t		size;
			size_t		capacity;
			value_type	*arr;
			Alloc		alloc;
		
		

	};
}



#endif
