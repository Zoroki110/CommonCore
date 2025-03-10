# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:21:17 by trouilla          #+#    #+#              #
#    Updated: 2025/03/10 13:24:53 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

LIBFT				= ./Libft/libft.a
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SRCS = $(SRC_DIR)philo.c $(SRC_DIR)init.c \
		$(SRC_DIR)init_args.c $(SRC_DIR)free.c \
				


OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make -C ./Libft

all: 				logo $(NAME)

logo:
	@printf "\033[1;32m :::::::::  :::    :::  :::::::  :::        ::::::::  \n"
	@printf "\033[1;35m :+:    :+: :+:    :+:     #     :+:       :+:    :+: \n"
	@printf "\033[1;32m +:+    +:+ +:+    +:+     #     +:+       +:+    +:+ \n"
	@printf "\033[1;35m +#++:++#+  +#++:++#++     #     +#+       +#+    +:+ \n"
	@printf "\033[1;32m +#+        +#+    +#+     #     +#+       +#+    +#+ \n"
	@printf "\033[1;35m #+#        #+#    #+#     #     #+#       #+#    #+# \n"
	@printf "\033[1;32m ###        ###    ###  #######  ########   ########  \n"
	@printf "\033[1;31m \n"
	@printf "\033[1;36m                      DINING PHILOSOPHERS              \n"
	@printf "\033[1;32m                      ==================               \n"
	@printf "\033[1;35m                          ┌─┬─┬─┐                      \n"
	@printf "\033[1;32m                          │🍽️│🍴│🧠│                   \n"
	@printf "\033[1;35m                          └─┴─┴─┘                      \n"
	
$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./Libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re logo