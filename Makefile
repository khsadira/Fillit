# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schakor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:14:23 by schakor           #+#    #+#              #
#    Updated: 2018/01/09 13:47:15 by schakor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CC		=	gcc

CFLAGS	=	#-Wall -Werror -Wextra

SRC		=	main.c ft_read_file.c ft_treat_file.c ft_check_tetra.c ft_place_tetra.c

OBJ		=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
