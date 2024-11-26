# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:17:06 by trouilla          #+#    #+#              #
#    Updated: 2024/11/26 11:19:08 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra 

LIBFT = Libft
MY_LIBFT = $(LIBFT)/libft.a

NAME = so_long

MY_SOURCES = check_map.c check_path.c error.c free.c generate_map.c key_moves.c so_long.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(MAKE) -C $(MY_LIBFT)
	$(CC) -lmlx -framework OpenGL -framework Appkit  $(LIBFT) -o $(NAME) $(MY_OBJECTS)

$(MY_OBJECTS):
	$(CC) $(CFLAGS) ${@:.o=.c} -o $@

clean:
	$(MAKE) clean -C $(LIBFT)
	${RM} ${MY_OBJECTS}


fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all