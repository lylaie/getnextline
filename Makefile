# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: audumont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 11:31:29 by audumont          #+#    #+#              #
#    Updated: 2020/01/12 12:18:07 by audumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
NAME = get_next_line
NAME_BONUS = get_next_line_bonus
SRC = get_next_line.c get_next_line_utils.c
SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
INCLUDE = get_next_line.h
INCLUDE_BONUS = get_next_line_bonus.h
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(INCLUDE) 
	$(CC) $(CC_FLAGS) -c -o $@ $< 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(INCLUDE_BONUS)
	$(CC) $(CC_FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

%.o: %.c $(INCLUDE_BONUS)
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(OBJ) $(OBJ_BONUS)
re: fclean all
