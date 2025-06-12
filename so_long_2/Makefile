# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 08:49:58 by trouilla          #+#    #+#              #
#    Updated: 2025/06/12 08:50:14 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

LIBFT_DIR		= Libft
LIBFT			= -lft
LIBFT_INC		= -I$(LIBFT_DIR)
LIBFT_LINK		= -L$(LIBFT_DIR)

MLX_DIR			= mlx
MLX_LIB			= -lmlx -lXext -lX11
MLX_INC			= -I$(MLX_DIR)
MLX_LINK		= -L$(MLX_DIR)

SRC_DIR			= src
OBJ_DIR			= obj

HEADERS			= -Iinclude

SRCS_NAMES		= check map main path free generate_map file_img map_print\
					move_player key_move get_player_pos\

SRCS			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS_NAMES)))
OBJS			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS_NAMES)))

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(OBJS) $(LIBFT_LINK) $(MLX_LINK) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@echo "\033[1;32m✔︎ so_long built successfully (Linux)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) $(LIBFT_INC) $(MLX_INC)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re