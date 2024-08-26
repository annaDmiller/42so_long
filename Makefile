NAME = so_long

CC = cc

CC_FLAGS = -Wall -Werror -Wextra -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS = main.c

DIR_SRCS = src/

SRCS := $(addprefix $(DIR_SRCS), $(SRCS))

LIBFT_FLAG = -Llibft -lft

RM = rm

RM_FLAG = -f

MAKE = make

MAKE_FLAG = --no-print-directory

LIBFT_DIR = ./libft/

LIBFTA = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)  ${LIBFTA}
	$(CC) $(CC_FLAGS) $^ $(LIBFT_FLAG) -o $(NAME)

${LIBFTA}:
	$(MAKE) $(MAKE_FLAG) -C $(LIBFT_DIR)

clean:
	$(RM) $(RM_FLAG) $(LIBFT_DIR)*.o $(DIR_SRCS)*.o

fclean: clean
	$(RM) $(RM_FLAG) $(LIBFTA) $(NAME)

re: fclean all