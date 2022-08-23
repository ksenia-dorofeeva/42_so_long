NAME		=	so_long

SRCS		=	src/main.c src/map_parser.c src/get_next_line.c \
				src/get_next_line_utils.c src/error_manager.c \
				src/draw.c src/init.c src/utils.c src/map_checker.c

OBJS 		= 	$(SRCS:.c=.o)

HEAD 		= 	./so_long.h

CC 			= 	gcc

FLAGS 		= 	-Wall -Wextra -Werror 

RM 			= 	rm -f

MLX			=	-L mlx -lmlx -framework OpenGL -framework AppKit

.PHONY: 		all clean fclean re

all:			$(NAME)

$(NAME):	$(OBJS) 
	make -s -C ./mlx
	$(CC) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c   $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@$(RM) $(OBJS)
	make clean -C ./mlx
	@echo "clean is done!"


fclean: clean
		@$(RM) $(NAME)
		@echo "full clean is done!"

re: 	fclean all