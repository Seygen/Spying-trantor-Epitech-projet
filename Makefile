##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRC		=	controller.c	\
			spying.c		\
			socket.c		\
			get_next_line.c 

OBJ		= 	$(SRC:.c = o)

NAME	=	drone_RC

all:		$(NAME)

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ) -Wall -Wextra 

thread: 	$(OBJ)		
			gcc -o $(NAME) $(OBJ) -Wall -Wextra -Werror

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all
