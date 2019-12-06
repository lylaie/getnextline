CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
NAME = get_next_line
SRC = get_next_line.c get_next_line_utils.c
INCLUDE = get_next_line.h
OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(INCLUDE) 
	$(CC) $(CC_FLAGS) -c -o $@ $< 

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)

re: fclean all
