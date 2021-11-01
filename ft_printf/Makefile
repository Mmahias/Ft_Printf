SRCS	= ft_atoi.c ft_strncmp.c ft_conv_c.c ft_conv_id.c ft_conv_p.c ft_conv_per.c ft_conv_s.c ft_conv_u.c ft_conv_x.c ft_conv_per.c ft_isconv.c ft_isdigit.c ft_isflag.c ft_prec_empty.c ft_itoa.c ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putnbr_base.c ft_putnbr_uintptr.c ft_strlen.c ft_utoa.c

OBJS	= ${SRCS:.c=.o}


NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -f

.c.o: 
	  ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):  ${OBJS}
	  ar -rcs ${NAME} ${OBJS}

all:      ${NAME}

clean:
	  ${RM} ${OBJS}

fclean:	  clean
	  ${RM} ${NAME}

re:	  fclean all

.PHONY:   all clean fclean re
