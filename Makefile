# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 16:51:06 by iouardi           #+#    #+#              #
#    Updated: 2023/02/14 16:51:59 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 			vector

CPPFLAGS=			-Wall -Werror -Wextra -std=c++98

CC=				c++

SRC_FILES=		main.cpp


HEADER_FILES=	vector.hpp \
				random_access_iterator.hpp
				
				
OBJ_FILES=			$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
