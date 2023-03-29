NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I /usr/include/ -I /usr/local/include -I ./include
LIBDIR	=	-L/usr/local/lib -L/usr/lib
LIB		=	-lmlx -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT	=	./libft/libft.a

SRCS	=	$(shell find srcs/ -name "*.c")
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

all: $(NAME)
$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR) $(LIB) -o $(NAME)

$(LIBFT):
	@make -C ./libft

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

