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

SRC_FILES  = ft_ls.c errors.c options.c
SRC_FILES += command/command.c command/options.c command/paths.c
SRC_FILES += linked_list/add_file.c linked_list/new_file.c linked_list/order_files.c \
			 linked_list/swap_files.c
SRC_FILES += linked_list/sort/sort_by_date.c

SRC  = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ  = $(addprefix $(OBJ_DIR)/, $(subst .c,.o, $(SRC_FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB = -L libft/ -lft
LIBFT_INC = libft/includes

KNRM = "\x1B[0m"
KGRN = "\x1B[1;32m"

.PHONY: all clean fclean re

all:
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

$(NAME): $(OBJ)
	@echo "Creation de l'executable..."
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

obj/ft_ls.o: src/ft_ls.c

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilation du fichier "$(KGRN)$(notdir $(subst .c,,$<))$(KNRM)
	@mkdir -p $(dir $@) && $(CC) $(CFLAGS) -I $(LIBFT_INC) -I $(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
