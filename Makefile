NAME = libftprintf.a

CC = gcc

INCLUDE = -I ./includes

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

SRC = ./

MAIN = $(addprefix $(SRC), \
	ft_printf.c utils.c)

OBJ = $(MAIN:%.c=%.o)

$(NAME): $(OBJ)
	make all -C ./libft
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out
	make clean -C ./libft


fclean:	clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all