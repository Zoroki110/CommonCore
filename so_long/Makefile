# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:17:06 by trouilla          #+#    #+#              #
#    Updated: 2024/12/02 19:35:16 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra

LIBFT_DIR = Libft         
LIBFT = -lft               
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

NAME = so_long

MY_SOURCES = check_map.c check_path.c error.c \
				free.c generate_map.c key_move.c \
				so_long.c file_image.c close_screen.c \
				map_print.c move.c 
MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(MY_OBJECTS) $(MLX_FLAGS) -L$(LIBFT_DIR) $(LIBFT)

$(MY_OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@  

clean:
	$(MAKE) clean -C $(LIBFT_DIR)  
	$(RM) $(MY_OBJECTS)            

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)  
	$(RM) $(NAME)                   

re: fclean all  
