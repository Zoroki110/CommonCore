# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 10:58:46 by trouilla          #+#    #+#              #
#    Updated: 2024/12/11 11:12:58 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT				= ./libft/libft.a
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SRCS = $(SRC_DIR)push.c $(SRC_DIR)reverse_rotate.c \
		$(SRC_DIR)rotate.c $(SRC_DIR)swap.c $(SRC_DIR)sort_stack.c \
		$(SRC_DIR)sort_three.c $(SRC_DIR)push_swap.c $(SRC_DIR)error.c \
		$(SRC_DIR)push_swap_utils.c $(SRC_DIR)split_push_swap.c $(SRC_DIR)stack_define.c \
		$(SRC_DIR)value_a_to_b.c $(SRC_DIR)value_b_to_a.c
				


OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make -C ./libft

all: 				logo $(NAME)

logo:
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
	
$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re logo