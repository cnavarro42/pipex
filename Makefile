NAME =		pipex

CC =		gcc

CFLAGS =    -Wall -Wextra -Werror -g

#DFLAGS =	-g -fsanitize=address

RM =		rm -rf

SRCS_C		= ../main.c dad.c writer.c reader.c utils.c pathing.c

SRCS		= $(addprefix srcs/, $(SRCS_C))

OBJS		= $(SRCS:.c=.o)

INCLUDES	= includes

LIBFT		= libft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(LIBFT)/libft.a $(OBJS) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<
clean:
	@$(RM) $(OBJS)
	@make fclean -C $(LIBFT)
fclean:
	@$(RM) $(OBJS)
	@make fclean -C $(LIBFT)
re:			fclean all

.PHONY:		all clean fclean re