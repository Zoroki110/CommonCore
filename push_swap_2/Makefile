# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trouilla <trouilla@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 09:13:12 by trouilla          #+#    #+#              #
#    Updated: 2025/06/14 10:48:11 by trouilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
INC_DIR		= inc

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/stack.c \
			  $(SRC_DIR)/stack_2.c \
  			  $(SRC_DIR)/atoi.c \
   			  $(SRC_DIR)/parse_args.c \
			  $(SRC_DIR)/operation.c \
			  $(SRC_DIR)/operation_utils.c \
			  $(SRC_DIR)/operation_utils_2.c \
			  $(SRC_DIR)/parsing.c \
			  $(SRC_DIR)/sorting.c \
			  $(SRC_DIR)/sort_small.c \
			  $(SRC_DIR)/sort_large.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/error.c

OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re