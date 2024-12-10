# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toikirouillard <toikirouillard@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:58:46 by trouilla          #+#    #+#              #
#    Updated: 2024/12/10 22:27:38 by toikirouill      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wextra -Wall -Werror -I
RM = rm -f

SRC = $(SRC_DIR)operation/push.c $(SRC_DIR)operation/reverse_rotate.c \
		$(SRC_DIR)operation/rotate.c $(SRC_DIR)operation/swap.c $(SRC_DIR)operation/sort_stack.c \
		$(SRC_DIR)operation/sort_three.c push_swap.c error.c \
		push_swap_utils.c split_push_swap.c stack_define.c \
		value_a_to_b.c value_b_to_a.c
				

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

start:
		@make all

$(LIBFT):
		@make -C ./libft

logo : 		
	@printf "\033[1;32m              :::::::::  :::    :::  ::::::::   :::    :::    \n"
	@printf "\033[1;35m             :+:    :+: :+:    :+:  :+:    :+: :+:    :+:    \n"	
	@printf "\033[1;32m            +:+    +:+ +:+    +:+  +:+        +:+    +:+    \n"
	@printf "\033[1;35m           +#++:++#+  +#+    +:+  +#++:++#++ +#++:++#++    \n"
	@printf "\033[1;32m          +#+        +#+    +#+     	+#+ +#+    +#+    \n"
	@printf "\033[1;35m         #+#        #+#    #+#  #+#    #+# #+#    #+#    \n"
	@printf "\033[1;32m        ###         ########    ########  ###    ###    \n"
	@printf "\033[1;31m \n"
	@printf "\033[1;32m         ::::::::   :::       :::     :::     :::::::::    \n"
	@printf "\033[1;35m        :+:    :+: :+:       :+:   :+: :+:   :+:    :+:   \n"
	@printf "\033[1;32m       +:+        +:+       +:+  +:+   +:+  +:+    +:+   \n"
	@printf "\033[1;35m     #++:++#++   +#+  +:+  +#+ +#++:++#++: +#++:++#+    \n"
	@printf "\033[1;32m          +#+   +#+ +#+#+ +#+ +#+     +#+ +#+          \n"
	@printf "\033[1;35m   #+#   #+#    #+#+# #+#+#  #+#     #+# #+#          \n"
	@printf "\033[1;32m   ########     ###   ###   ###     ### ###          \n"
	@printf "\033[1;35m \n"
	
all : logo $(NAME)

$(NAME): 		$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: start all clean fclean re logo