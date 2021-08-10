NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= $(shell find . -name '*.c' ! -name 'ft_lst*.c')
OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= $(shell find . -name 'ft_lst*.c')
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.PHONY:		all clean fclean re bonus

clean:
			${RM} ${OBJS} $(BONUS_OBJS)

fclean:		clean
			${RM} ${NAME}

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
			ranlib $(NAME)

all:		$(NAME)
	
re:			fclean all bonus
