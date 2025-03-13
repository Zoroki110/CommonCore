# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:21:17 by trouilla          #+#    #+#              #
#    Updated: 2025/03/13 15:15:04 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

SRCS = $(SRC_DIR)philo.c $(SRC_DIR)init.c \
		$(SRC_DIR)init_args.c $(SRC_DIR)free.c \
		$(SRC_DIR)monitor_death.c $(SRC_DIR)routine.c \
		$(SRC_DIR)monitor.c $(SRC_DIR)utils_routine.c

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

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

$(NAME): 			$(OBJ_DIR) $(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) -r $(OBJ_DIR)

re: 				fclean all

.PHONY: 			start all clean fclean re logo