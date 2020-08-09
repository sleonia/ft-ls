.PHONY: libftprintf, all, clean, fclean, re

# =========== #
#    PARSER   #
# =========== #

PARSER_FILES =							\
				parser.c				\
				read_files.c			\
				fill_file.c				\
				read_flags.c			\
				validate_flags.c		\

PARSER_DIR = ./sources/parser/

OBJ_PARSER_FILES = $(addprefix $(OBJ_DIR), $(PARSER_FILES:.c=.o))

# =========== #
#    PRINT    #
# =========== #

PRINT_FILES =							\
			print.c						\
			print_all_info.c			\
			print_all_things.c			\
			print_directory.c			\
			print_file.c				\
			print_illegal_opt.c			\
			print_link_value.c			\
			print_size.c				\
			print_with_color.c			\
			print_column.c				\

PRINT_DIR = ./sources/print/

OBJ_PRINT_FILES = $(addprefix $(OBJ_DIR), $(PRINT_FILES:.c=.o))

# =========== #
#    SORT	  #
# =========== #

SORT_FILES =							\
				reverse.c				\
				sort.c					\

SORT_DIR = ./sources/sort/

OBJ_SORT_FILES = $(addprefix $(OBJ_DIR), $(SORT_FILES:.c=.o))

# =========== #
#    UTILS    #
# =========== #

UTILS_FILES =							\
				build_path.c			\
				config.c				\
				free.c					\
				get_attributes.c		\
				get_type.c				\
				utils.c					\
				del_last.c				\
				free_matrix.c			\

UTILS_DIR = ./sources/utils/

OBJ_UTILS_FILES = $(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))

# =========== #
#	MAIN	  #
# =========== #

MAIN_FILES =							\
			main.c						\

MAIN_DIR = ./sources/

OBJ_MAIN_FILES = $(addprefix $(OBJ_DIR), $(MAIN_FILES:.c=.o))


# =========== #
#	INCLUDES  #
# =========== #

INCLUDES_FILES_LIST =					\
			types.h						\
			parser/parser.h				\
			sort/sort.h					\
			print/print.h				\
			utils/utils.h				\

INCLUDES_DIR = 	./includes/

INCLUDES_FILES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES_LIST))

# =========== #
#	BUILD	  #
# =========== #

NAME = ft_ls

OBJ = 									\
		$(OBJ_PARSER_FILES)				\
		$(OBJ_PRINT_FILES)				\
		$(OBJ_SORT_FILES)				\
		$(OBJ_UTILS_FILES)				\
		$(OBJ_MAIN_FILES)				\

OBJ_DIR = ./objects/

SRC_DIR = ./sources/

COMPILE_FLAGS = -Wall -Werror -Wextra -g

COMPILE = gcc $(COMPILE_FLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_INC)

FT_LS_LIBS = -L $(LIBFT_DIR) -lftprintf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INCLUDES_FILES)
	make lib_refresh
	$(COMPILE) $(FT_LS_LIBS) $(OBJ) -o $(NAME) $(FRAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(PARSER_DIR)%.c $(INCLUDES_FILES)
	$(COMPILE) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINT_DIR)%.c $(INCLUDES_FILES)
	$(COMPILE) -c $< -o $@

$(OBJ_DIR)%.o: $(SORT_DIR)%.c $(INCLUDES_FILES)
	$(COMPILE) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(INCLUDES_FILES)
	$(COMPILE) -c $< -o $@

$(OBJ_DIR)%.o: $(MAIN_DIR)%.c $(INCLUDES_FILES)
	$(COMPILE) -c $< -o $@

lib_refresh:
	make -C $(LIBFT_DIR)

clean:
	clear
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean $(NAME)


# =========== #
# 	LIBFT	  #
# =========== #

LIBFT_DIR =					\
	./libftprintf/			\

LIBFT_INC = 				\
	./libftprintf/			\

$(LIBFT):
	@make -C $(LIBFT_DIR)
