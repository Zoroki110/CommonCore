# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 10:11:23 by trouilla          #+#    #+#              #
#    Updated: 2024/12/20 11:09:18 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
SRCS = pipex.c path.c free.c child.c
CC = gcc
CCFLAG = -Wall -Werror -Wextra
LIBFT_DIR = ./Libft
OBJ_DIR = obj
OBJECT = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
D_SRCS = ./src/

all: $(NAME)

$(OBJ_DIR)/%.o: $(D_SRCS)%.c | $(OBJ_DIR)
	@$(CC) $(CCFLAG) -I$(LIBFT_DIR) -I/includes -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJECT)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CCFLAG) -o $(NAME) $(OBJECT) -L$(LIBFT_DIR) -lft

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf ./$(NAME)

re: fclean all

.PHONY: all clean fclean re bonus