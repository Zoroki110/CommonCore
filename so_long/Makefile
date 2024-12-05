# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 14:17:06 by trouilla          #+#    #+#              #
#    Updated: 2024/12/04 11:26:01 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -c -Wall -Werror -Wextra -fsanitize=address -g
LDFLAGS = -lmlx -framework OpenGL -framework Appkit -lft -fsanitize=address -g
LIBFT_DIR = Libft
LIBFT = -lft

RM = rm -f

SOURCES_DIR = src/
OBJ_DIR = obj/
BONUS_SOURCES_DIR = src_bonus/
BONUS_OBJ_DIR = obj_bonus/

MY_SOURCES = check_map check_path error free generate_map key_move \
				so_long file_image close_screen map_print move move_e

MY_SOURCES_BONUS = check_map_bonus check_path_bonus error_bonus \
				free_bonus generate_map_bonus key_move_bonus \
				so_long_bonus file_image_bonus close_screen_bonus \
				map_print_bonus move_bonus move_e_bonus

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(MY_SOURCES)))
SRC = $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(MY_SOURCES)))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(addsuffix .o, $(MY_SOURCES_BONUS)))
BONUS_SRC = $(addprefix $(BONUS_SOURCES_DIR), $(addsuffix .c, $(MY_SOURCES_BONUS)))				

HEAD = ./include/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -L$(LIBFT_DIR) $(LIBFT)
	@echo "\033[1;32m./so_long created\n"

$(NAME_BONUS): $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(BONUS_OBJ) $(LDFLAGS) -o $(NAME_BONUS) -L$(LIBFT_DIR) $(LIBFT)
	@echo "\033[1;32m./so_long_bonus created\n"

$(OBJ_DIR)%.o : $(SOURCES_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

$(BONUS_OBJ_DIR)%.o : $(BONUS_SOURCES_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)            

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)                

re: fclean all  

.PHONY: all clean fclean re bonus
