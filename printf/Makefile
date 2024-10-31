# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 11:14:50 by trouilla          #+#    #+#              #
#    Updated: 2024/10/24 16:57:36 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -fsanitize=address -g3
AR = ar
ARFLAGS = rsc
RM = rm -rf

SRCS = ft_hexptr.c ft_print_hex_min.c ft_print_hex_Maj.c ft_print_hex_p.c ft_printf.c \
	   ft_putchar.c ft_putnbr.c ft_putnbr_u.c ft_putstr.c

OBJS = ${SRCS:.c=.o}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} 
	${AR} ${ARFLAGS} $(NAME) ${OBJS}

clean : 
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all
