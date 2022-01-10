# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 14:59:43 by fathjami          #+#    #+#              #
#    Updated: 2022/01/10 12:02:39 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror

NAME = so_long
FILES = so_long_bonus parsing_bonus/parsing0 parsing_bonus/parsing1 parsing_bonus/parsing2 clean_bonus fill_bonus movements_bonus itoa
SRC = $(FILES:=.c)
OBJ = $(FILES:=.o)

LINKES =  -I so_long_bonus.h -I /usr/local/include -L /usr/local/lib \
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

$(NAME): $(OBJ) so_long_bonus.h
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LINKES)
	@echo "$(BGREEN)$(BOLD)$(white) [:)] SUCCESS $(END)"

%.o: %.c so_long_bonus.h
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJ)
	@echo "$(BYELLOW)$(BOLD)$(white) [:)] CLEAN $(END)"
	

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BYELLOW)$(BOLD)$(white) [:)] FCLEAN $(END)"


re: fclean all

.PHONY: all clean fclean re
