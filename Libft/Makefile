# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 15:40:23 by trouilla          #+#    #+#              #
#    Updated: 2024/10/21 15:40:35 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_toupper.c ft_tolower.c ft_strrchr.c ft_strnstr.c ft_strlen.c \
			ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_strchr.c \
			ft_memset.c ft_memmove.c ft_memcpy.c ft_memcmp.c \
			ft_memchr.c ft_isprint.c ft_isdigit.c ft_isascii.c \
			ft_isalpha.c ft_isalnum.c ft_calloc.c ft_bzero.c ft_atoi.c \
			ft_substr.c ft_strtrim.c ft_strmapi.c \
			ft_strjoin.c ft_striteri.c ft_split.c \
			ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
			ft_putchar_fd.c ft_strncmp.c ft_itoa.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

NAME = libft.a

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I -fsanitize=address -g3

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar -rsc $(NAME) ${OBJS}

bonus : ${OBJS} ${OBJSBONUS}
	ar -rsc ${NAME} ${OBJS} ${OBJSBONUS}

all : ${NAME}

clean : 
	rm -f ${OBJS} ${OBJSBONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all
