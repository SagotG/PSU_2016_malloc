##
## Makefile for  in /root/rendu/PSU_2016_malloc/
##
## Made by Guillaume Sagot
## Login   <guillaume.sagot@epitech.eu>
##
## Started on  Mon Jan 23 19:06:25 2017 Guillaume Sagot
## Last update Feb Feb 6 19:23:22 2017 Guillaume Sagot
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror -fPIC -pthread
CFLAGS	+=	-Iincludes

LDFLAGS	=	-shared -o $(NAME)

NAME	=	libmy_malloc.so

SRC	=	sources/malloc.c		\
		sources/realloc.c		\
		sources/free.c			\
		sources/show_alloc_mem.c	\

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(LDFLAGS) $(OBJ)
test	:
		export LD_PRELOAD=$(PWD)/$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
