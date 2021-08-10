NAME		= Minitalk

SRCS		= server.c client.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

INCLUDES	= libft

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

LIBFT		= ./libft

LINKERS		= -L$(LIBFT) -lft

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	client.o server.o
			$(MAKE) bonus -C $(LIBFT)
			$(CC) $(CFLAGS)  -I$(INCLUDES) $(LINKERS) client.o -o client
			$(CC) $(CFLAGS)  -I$(INCLUDES) $(LINKERS) server.o -o server
clean:
			$(MAKE) clean -C $(LIBFT)
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT)
			$(RM) client server

re:			fclean all

.PHONY:		all clean fclean re

