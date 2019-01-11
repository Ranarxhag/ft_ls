# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 17:30:29 by bjovanov          #+#    #+#              #
#    Updated: 2019/01/10 17:30:30 by bjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

NAME = ft_ls

SRC_FILES = ft_ls.c config.c

SRC  = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ  = $(addprefix $(OBJ_DIR)/, $(subst .c,.o, $(SRC_FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

KNRM = "\x1B[0m"
KGRN = "\x1B[1;32m"

.PHONY: all clean fclean re

all:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

$(NAME): $(OBJ)
	@echo "Creation de l'executable..."
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilation du fichier "$(KGRN)$(notdir $(subst .c,,$<))$(KNRM)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:

fclean: clean

re: fclean all
