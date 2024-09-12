NAME = so_long

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3

SRCS = main.c error.c map_initialization.c str_realloc.c map_validation.c map_validation_border.c \
		map_validation_collectibles.c create_temp_arr_for_validation.c screen_creation.c \
		screen_hook_logic.c

DIR_SRCS = src/

OBJ = $(addprefix $(DIR_SRCS), $(SRCS:%.c=%.o))

LIBFT_FLAG = -Llibft -lft

RM = rm

RM_FLAG = -f

MAKE = make

MAKE_FLAG = --no-print-directory

LIBFT_DIR = ./libft/

LIBFTA = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)  ${LIBFTA}
	$(CC) $^ $(CC_FLAGS) $(LIBFT_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

${LIBFTA}:
	$(MAKE) $(MAKE_FLAG) -C $(LIBFT_DIR)

clean:
	$(RM) $(RM_FLAG) $(LIBFT_DIR)*.o $(DIR_SRCS)*.o

fclean: clean
	$(RM) $(RM_FLAG) $(LIBFTA) $(NAME)

re: fclean all