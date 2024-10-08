DIRSRC		= ./src/

DIRINC		= includes/

DIROBJ		= ./objs/

LIBFT_PATH	=	./libft/

SRC			=	flag_utils \
				ft_print_base_10 \
				ft_print_ptr \
				ft_printf_unsigned \
				ft_printpourcent \
				ft_put_2 \
				ft_put \
				ft_strlen \
				ft_printf \

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= ft_printf.a

NAMELFT		= libft.a

CC			= cc
RM			= rm -f
AR			= ar rcs
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror -g3

.c.o:
			@${CC} ${CFLAGS} -c -I${DIRINC} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@cp ../libft.a ./$@
			@${AR} $@ ${OBJS}

all:		$(NAME)

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
