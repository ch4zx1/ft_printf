# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfischer <cfischer@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 03:19:39 by cfischer          #+#    #+#              #
#    Updated: 2022/06/25 20:51:33 by cfischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

SRC = ft_printf.c utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJS): 
	$(CC) $(CFLAGS) $(SRC) -C

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft


fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re