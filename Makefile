NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I /usr/include/ -I /usr/local/include -I ./include
LIBDIR	=	-L/usr/local/lib -L/usr/lib
#LIB_LX	=	-lmlx -lmlx_Linux -lXext -lX11 -lm -lz
LIB		=	-L/usr/X11R6/lib -lXext -lX11 -lmlx -framework OpenGL -framework Appkit
LIBFT	=	./libft/libft.a
MLXLIB	=	./minilibx-linux/libmlx_Darwin.a
#MLXLIB_LX	=	./minilibx-linux/libmlx_Linux.a
SRCS	=	$(shell find srcs/ -name "*.c")
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(LIBDIR) $(LIB) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft
$(MLXLIB):
	@make -C ./minilibx-linux

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

libft:
	make -C	./libft

clean:
	rm -rf $(OBJDIR)
	make clean -C ./libft
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
re:	fclean all

.PHONY:
	all clean fclean re

