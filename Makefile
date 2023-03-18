NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I /usr/include/ -I /usr/local/include -I ./include

SRCS	=	$(shell find srcs/ -name "*.c")
OBJDIR	=	obj
OBJS	=	$(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(INCLUDE) $(CFLAGS) -o $@ -c $<

all: $(NAME)
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L/usr/local/lib -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $@
