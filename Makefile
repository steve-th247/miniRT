NAME	= miniRT

CC		= cc -g #-fsanitize=address #-fsanitize=memory
RM		= rm -rf

CFLAGS 	= -Wall -Wextra -Werror

SRC_PATH = srcs/
OBJ_PATH = objs/

SRCS     = $(wildcard $(SRC_PATH)*.c)

OBJS     = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRCS))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -Ilibft -I./mlx -c $< -o $@

${NAME}:	${OBJS}
	@make bonus -C libft
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