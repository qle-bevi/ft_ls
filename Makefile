NAME = ft_ls

SRC = main.c parse_options.c print_error.c print_entries.c new_entry.c \
			elst_del.c elst_pop.c load_dir.c elst_add.c elst_sort.c cmp_alpha.c \
			cmp_alpharev.c cmp_time.c cmp_timerev.c print_entry.c print_entry_long.c \
			cmp_size.c cmp_sizerev.c

INCLUDES = -Iincludes -Ilibft/includes
LIB_FLAGS = -Llibft -lft
FLAGS = -Wextra -Werror -Wall $(INCLUDES)

OBJ_DIR = obj
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc -Ofast $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME)
	@echo "\n✅  FT_LS BUILT !"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all
