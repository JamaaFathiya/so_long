# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 14:59:43 by fathjami          #+#    #+#              #
#    Updated: 2021/12/18 16:22:26 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

NAME = long
FILES = so_long
SRC = $(FILES:=.c)
OBJ = $(FILES:=.o)

LINKES =  -I libft -I /usr/local/include -L /usr/local/lib \
    -l mlx -framework OpenGL -framework Appkit

bold := $(shell tput bold)
#BACKGROUND COLORS
BRED = \x1b[41m
BGREEN = \x1b[42m
BYELLOW = \x1b[43m

#COLORS
White = \033[0;37m
YELLOW = \x1b[33m

END = \x1b[0m
BOLD = \x1b[1m
UNDER = \x1b[4m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKES)
	@echo "$(BGREEN)$(BOLD)$(white) [:)] SUCCESS "

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJ)
	@echo "$(BYELLOW)$(BOLD)$(white) [:)] CLEAN "
	

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BYELLOW)$(BOLD)$(white) [:)] FCLEAN "


re: fclean all

.PHONY: all clean fclean re