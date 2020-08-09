NAME = libftprintf.a

SRC =   ft_printf.c additional.c print_nums.c print_text.c search_details.c\
        print_oct_hex.c ft_itoa_base.c print_address.c print_binary.c ft_print_bf.c\
        print_long.c print_long_long.c print_short.c print_r.c width_and_precision.c\
        print_decimal_width.c print_colour.c print_unsigned_width.c print_nondecimal_width.c\
        expanded_allocation.c print_short_short.c itoa_2.c ft_print_f.c search_else_details.c\

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc $(FLAGS) -c -g $(SRC) -I include/ft_printf.h -I libft/libft.h
	ar -r $@ $(OBJ)
	ranlib $@

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

re: fclean all
