NAME	=	push_swap

CC		= gcc 

CFLAGS	=	-Wall -Wextra -Werror

SRC	=	push_swap.c\
		find_best.c \
		free_stuff.c\
		ft_calculate_moves.c \
		lis.c \
		moves1.c\
		moves2.c\
		moves3.c\
		sort_a_b.c \
		sort_three.c\
		sort.c\
		upload_list.c\
		utils.c\
		ft_moves_type.c \
		ft_argv_check.c \

OBJ	=	$(SRC:.c=.o)

LIBFT = libft/libft.a

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@

$(NAME):	$(OBJ)
			@make -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			@make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			@make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re
