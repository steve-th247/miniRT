NAME	= miniRT

CC		= cc
RM		= rm -rf

CFLAGS 	= -Wall -Wextra -Werror

SRC_PATH = srcs/
OBJ_PATH = objs/

#SRC		=	.c/

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -Ilibft -I./mlx -c $< -o $@

${NAME}:	${OBJS}
	@make -C libft
	@make -C mlx
	@${CC} ${CFLAGS} $^ -Llibft -lft -L./mlx -lm -lmlx -lglfw -ldl -lX11 -lXext -o ${NAME}

clean:
	@make clean -C libft
	@make clean -C mlx
	@${RM} ${OBJ_PATH}

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

.PHONY:		 all clean fclean re