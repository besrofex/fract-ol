NAME = fractol
OBJS = fractol.o mlx.o utils.o events.o complex_op.o
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS)  -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all