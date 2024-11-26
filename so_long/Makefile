# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:17:06 by trouilla          #+#    #+#              #
#    Updated: 2024/11/26 11:41:18 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra

LIBFT_DIR = Libft          # Répertoire de la bibliothèque Libft
LIBFT = -lft               # Nom de la bibliothèque sans le préfixe "lib" ni l'extension
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit  # Options pour MLX et OpenGL

NAME = so_long

MY_SOURCES = check_map.c check_path.c error.c free.c generate_map.c key_move.c so_long.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR)      # Compile la bibliothèque Libft
	$(CC) -o $(NAME) $(MY_OBJECTS) $(MLX_FLAGS) -L$(LIBFT_DIR) $(LIBFT)  # Lien avec Libft et MLX

$(MY_OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@  # Compilation de chaque fichier source en fichier objet

clean:
	$(MAKE) clean -C $(LIBFT_DIR)  # Nettoyage dans le répertoire Libft
	$(RM) $(MY_OBJECTS)             # Suppression des fichiers objets

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)  # Nettoyage complet dans le répertoire Libft
	$(RM) $(NAME)                   # Suppression du fichier exécutable

re: fclean all  # Reconstruction complète
